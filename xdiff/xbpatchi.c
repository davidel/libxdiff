/*    Copyright 2023 Davide Libenzi
 * 
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 * 
 *        http://www.apache.org/licenses/LICENSE-2.0
 * 
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 * 
 */


#include "xinclude.h"


#define XDL_MOBF_MINALLOC 128


typedef struct s_mmoffbuffer {
	long off, size;
	char *ptr;
} mmoffbuffer_t;



static int xdl_copy_range(mmfile_t *mmf, long off, long size, xdemitcb_t *ecb) {
	if (xdl_seek_mmfile(mmf, off) < 0) {

		return -1;
	}
	if (xdl_copy_mmfile(mmf, size, ecb) != size) {

		return -1;
	}

	return 0;
}


int xdl_bpatch(mmfile_t *mmf, mmfile_t *mmfp, xdemitcb_t *ecb) {
	long size, off, csize, osize;
	unsigned long fp, ofp;
	char const *blk;
	unsigned char const *data, *top;
	mmbuffer_t mb;

	if ((blk = (char const *) xdl_mmfile_first(mmfp, &size)) == NULL ||
	    size < XDL_BPATCH_HDR_SIZE) {

		return -1;
	}
	ofp = xdl_mmf_adler32(mmf);
	osize = xdl_mmfile_size(mmf);
	XDL_LE32_GET(blk, fp);
	XDL_LE32_GET(blk + 4, csize);
	if (fp != ofp || csize != osize) {

		return -1;
	}

	blk += XDL_BPATCH_HDR_SIZE;
	size -= XDL_BPATCH_HDR_SIZE;

	do {
		for (data = (unsigned char const *) blk, top = data + size;
		     data < top;) {
			if (*data == XDL_BDOP_INS) {
				data++;

				mb.size = (long) *data++;
				mb.ptr = (char *) data;
				data += mb.size;

				if (ecb->outf(ecb->priv, &mb, 1) < 0) {

					return -1;
				}
			} else if (*data == XDL_BDOP_INSB) {
				data++;
				XDL_LE32_GET(data, csize);
				data += 4;

				mb.size = csize;
				mb.ptr = (char *) data;
				data += mb.size;

				if (ecb->outf(ecb->priv, &mb, 1) < 0) {

					return -1;
				}
			} else if (*data == XDL_BDOP_CPY) {
				data++;
				XDL_LE32_GET(data, off);
				data += 4;
				XDL_LE32_GET(data, csize);
				data += 4;

				if (xdl_copy_range(mmf, off, csize, ecb) < 0) {

					return -1;
				}
			} else {

				return -1;
			}
		}
	} while ((blk = (char const *) xdl_mmfile_next(mmfp, &size)) != NULL);

	return 0;
}


static unsigned long xdl_mmob_adler32(mmoffbuffer_t *obf, int n) {
	unsigned long ha;

	for (ha = 0; n > 0; n--, obf++)
		ha = xdl_adler32(ha, (unsigned char const *) obf->ptr, obf->size);

	return ha;
}


static long xdl_mmob_size(mmoffbuffer_t *obf, int n) {

	return n > 0 ? obf[n - 1].off + obf[n - 1].size: 0;
}


static mmoffbuffer_t *xdl_mmob_new(mmoffbuffer_t **probf, int *pnobf, int *paobf) {
	int aobf;
	mmoffbuffer_t *cobf, *rrobf;

	if (*pnobf >= *paobf) {
		aobf = 2 * (*paobf) + 1;
		if ((rrobf = (mmoffbuffer_t *)
		     xdl_realloc(*probf, aobf * sizeof(mmoffbuffer_t))) == NULL) {

			return NULL;
		}
		*probf = rrobf;
		*paobf = aobf;
	}
	cobf = (*probf) + (*pnobf);
	(*pnobf)++;

	return cobf;
}


static int xdl_mmob_find_cntr(mmoffbuffer_t *obf, int n, long off) {
	int i, lo, hi;

	for (lo = -1, hi = n; hi - lo > 1;) {
		i = (hi + lo) / 2;
		if (off < obf[i].off)
			hi = i;
		else
			lo = i;
	}

	return (lo >= 0 && off >= obf[lo].off && off < obf[lo].off + obf[lo].size) ? lo: -1;
}


static int xdl_bmerge(mmoffbuffer_t *obf, int n, mmbuffer_t *mbfp, mmoffbuffer_t **probf,
		      int *pnobf) {
	int i, aobf, nobf;
	long ooff, off, csize;
	unsigned long fp, ofp;
	unsigned char const *data, *top;
	mmoffbuffer_t *robf, *cobf;

	if (mbfp->size < XDL_BPATCH_HDR_SIZE) {

		return -1;
	}
	data = (unsigned char const *) mbfp->ptr;
	top = data + mbfp->size;

	ofp = xdl_mmob_adler32(obf, n);
	XDL_LE32_GET(data, fp);
	data += 4;
	XDL_LE32_GET(data, csize);
	data += 4;
	if (fp != ofp || csize != xdl_mmob_size(obf, n)) {

		return -1;
	}
	aobf = XDL_MOBF_MINALLOC;
	nobf = 0;
	if ((robf = (mmoffbuffer_t *) xdl_malloc(aobf * sizeof(mmoffbuffer_t))) == NULL) {

		return -1;
	}

	for (ooff = 0; data < top;) {
		if (*data == XDL_BDOP_INS) {
			data++;

			if ((cobf = xdl_mmob_new(&robf, &nobf, &aobf)) == NULL) {

				xdl_free(robf);
				return -1;
			}
			cobf->off = ooff;
			cobf->size = (long) *data++;
			cobf->ptr = (char *) data;

			data += cobf->size;
			ooff += cobf->size;
		} else if (*data == XDL_BDOP_INSB) {
			data++;
			XDL_LE32_GET(data, csize);
			data += 4;

			if ((cobf = xdl_mmob_new(&robf, &nobf, &aobf)) == NULL) {

				xdl_free(robf);
				return -1;
			}
			cobf->off = ooff;
			cobf->size = csize;
			cobf->ptr = (char *) data;

			data += cobf->size;
			ooff += cobf->size;
		} else if (*data == XDL_BDOP_CPY) {
			data++;
			XDL_LE32_GET(data, off);
			data += 4;
			XDL_LE32_GET(data, csize);
			data += 4;

			if ((i = xdl_mmob_find_cntr(obf, n, off)) < 0) {

				xdl_free(robf);
				return -1;
			}
			off -= obf[i].off;
			for (; i < n && csize > 0; i++, off = 0) {
				if ((cobf = xdl_mmob_new(&robf, &nobf, &aobf)) == NULL) {

					xdl_free(robf);
					return -1;
				}
				cobf->off = ooff;
				cobf->size = XDL_MIN(csize, obf[i].size - off);
				cobf->ptr = obf[i].ptr + off;

				ooff += cobf->size;
				csize -= cobf->size;
			}
			if (csize > 0) {

				xdl_free(robf);
				return -1;
			}
		} else {

			xdl_free(robf);
			return -1;
		}
	}
	*probf = robf;
	*pnobf = nobf;

	return 0;
}


static int xdl_bmerge_synt(mmoffbuffer_t *obf, int n, xdemitcb_t *ecb) {
	int i;
	mmbuffer_t *mb;

	if ((mb = (mmbuffer_t *) xdl_malloc(n * sizeof(mmbuffer_t))) == NULL) {

		return -1;
	}
	for (i = 0; i < n; i++) {
		mb[i].ptr = obf[i].ptr;
		mb[i].size = obf[i].size;
	}
	if (ecb->outf(ecb->priv, mb, n) < 0) {

		xdl_free(mb);
		return -1;
	}
	xdl_free(mb);

	return 0;
}


int xdl_bpatch_multi(mmbuffer_t *base, mmbuffer_t *mbpch, int n, xdemitcb_t *ecb) {
	int i, nobf, fnobf;
	mmoffbuffer_t *obf, *fobf;

	nobf = 1;
	if ((obf = (mmoffbuffer_t *) xdl_malloc(nobf * sizeof(mmoffbuffer_t))) == NULL) {

		return -1;
	}
	obf->off = 0;
	obf->ptr = base->ptr;
	obf->size = base->size;
	for (i = 0; i < n; i++) {
		if (xdl_bmerge(obf, nobf, &mbpch[i], &fobf, &fnobf) < 0) {

			xdl_free(obf);
			return -1;
		}
		xdl_free(obf);

		obf = fobf;
		nobf = fnobf;
	}
	if (xdl_bmerge_synt(obf, nobf, ecb) < 0) {

		xdl_free(obf);
		return -1;
	}
	xdl_free(obf);

	return 0;
}

