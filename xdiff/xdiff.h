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


#if !defined(XDIFF_H)
#define XDIFF_H

#ifdef __cplusplus
extern "C" {
#endif /* #ifdef __cplusplus */


#define XDF_NEED_MINIMAL (1 << 1)

#define XDL_PATCH_NORMAL '-'
#define XDL_PATCH_REVERSE '+'
#define XDL_PATCH_MODEMASK ((1 << 8) - 1)
#define XDL_PATCH_IGNOREBSPACE (1 << 8)
	
#define XDL_MMB_READONLY (1 << 0)

#define XDL_MMF_ATOMIC (1 << 0)

#define XDL_BDOP_INS 1
#define XDL_BDOP_CPY 2
#define XDL_BDOP_INSB 3



typedef struct s_memallocator {
	void *priv;
	void *(*malloc)(void *, unsigned int);
	void (*free)(void *, void *);
	void *(*realloc)(void *, void *, unsigned int);
} memallocator_t;

typedef struct s_mmblock {
	struct s_mmblock *next;
	unsigned long flags;
	long size, bsize;
	char *ptr;
} mmblock_t;

typedef struct s_mmfile {
	unsigned long flags;
	mmblock_t *head, *tail;
	long bsize, fsize, rpos;
	mmblock_t *rcur, *wcur;
} mmfile_t;

typedef struct s_mmbuffer {
	char *ptr;
	long size;
} mmbuffer_t;

typedef struct s_xpparam {
	unsigned long flags;
} xpparam_t;

typedef struct s_xdemitcb {
	void *priv;
	int (*outf)(void *, mmbuffer_t *, int);
} xdemitcb_t;

typedef struct s_xdemitconf {
	long ctxlen;
} xdemitconf_t;

typedef struct s_bdiffparam {
	long bsize;
} bdiffparam_t;


int xdl_set_allocator(memallocator_t const *malt);
void *xdl_malloc(unsigned int size);
void xdl_free(void *ptr);
void *xdl_realloc(void *ptr, unsigned int size);

int xdl_init_mmfile(mmfile_t *mmf, long bsize, unsigned long flags);
void xdl_free_mmfile(mmfile_t *mmf);
int xdl_mmfile_iscompact(mmfile_t *mmf);
int xdl_seek_mmfile(mmfile_t *mmf, long off);
long xdl_read_mmfile(mmfile_t *mmf, void *data, long size);
long xdl_write_mmfile(mmfile_t *mmf, void const *data, long size);
long xdl_writem_mmfile(mmfile_t *mmf, mmbuffer_t *mb, int nbuf);
void *xdl_mmfile_writeallocate(mmfile_t *mmf, long size);
long xdl_mmfile_ptradd(mmfile_t *mmf, char *ptr, long size, unsigned long flags);
long xdl_copy_mmfile(mmfile_t *mmf, long size, xdemitcb_t *ecb);
void *xdl_mmfile_first(mmfile_t *mmf, long *size);
void *xdl_mmfile_next(mmfile_t *mmf, long *size);
long xdl_mmfile_size(mmfile_t *mmf);
int xdl_mmfile_cmp(mmfile_t *mmf1, mmfile_t *mmf2);
int xdl_mmfile_compact(mmfile_t *mmfo, mmfile_t *mmfc, long bsize, unsigned long flags);

int xdl_diff(mmfile_t *mf1, mmfile_t *mf2, xpparam_t const *xpp,
	     xdemitconf_t const *xecfg, xdemitcb_t *ecb);
int xdl_patch(mmfile_t *mf, mmfile_t *mfp, int mode, xdemitcb_t *ecb,
	      xdemitcb_t *rjecb);

int xdl_merge3(mmfile_t *mmfo, mmfile_t *mmf1, mmfile_t *mmf2, xdemitcb_t *ecb,
	       xdemitcb_t *rjecb);

int xdl_bdiff_mb(mmbuffer_t *mmb1, mmbuffer_t *mmb2, bdiffparam_t const *bdp, xdemitcb_t *ecb);
int xdl_bdiff(mmfile_t *mmf1, mmfile_t *mmf2, bdiffparam_t const *bdp, xdemitcb_t *ecb);
int xdl_rabdiff_mb(mmbuffer_t *mmb1, mmbuffer_t *mmb2, xdemitcb_t *ecb);
int xdl_rabdiff(mmfile_t *mmf1, mmfile_t *mmf2, xdemitcb_t *ecb);
long xdl_bdiff_tgsize(mmfile_t *mmfp);
int xdl_bpatch(mmfile_t *mmf, mmfile_t *mmfp, xdemitcb_t *ecb);
int xdl_bpatch_multi(mmbuffer_t *base, mmbuffer_t *mbpch, int n, xdemitcb_t *ecb);


#ifdef __cplusplus
}
#endif /* #ifdef __cplusplus */

#endif /* #if !defined(XDIFF_H) */

