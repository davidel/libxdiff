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


#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include "xdiff.h"
#include "xtestutils.h"





static int xdlt_outf(void *priv, mmbuffer_t *mb, int nbuf) {
	int i;

	for (i = 0; i < nbuf; i++)
		if (!fwrite(mb[i].ptr, mb[i].size, 1, (FILE *) priv))
			return -1;

	return 0;
}


void usage(char const *prg) {

	fprintf(stderr,
		"use: %s --diff [-C N]   from-file  to-file\n"
		"     %s --patch         orig-file  patch-file\n"
		"     %s --bdiff [-B N]  from-file  to-file\n"
		"     %s --rabdiff       from-file  to-file\n"
		"     %s --bpatch        orig-file  patch-file\n",
		prg, prg, prg, prg, prg);
}


static void *wrap_malloc(void *priv, unsigned int size) {

	return malloc(size);
}


static void wrap_free(void *priv, void *ptr) {

	free(ptr);
}


static void *wrap_realloc(void *priv, void *ptr, unsigned int size) {

	return realloc(ptr, size);
}


int main(int argc, char *argv[]) {
	int i = 1, ctxlen = 3, bsize = 16, do_diff, do_patch, do_bdiff, do_bpatch, do_rabdiff;
	memallocator_t malt;
	mmfile_t mf1, mf2;
	xpparam_t xpp;
	xdemitconf_t xecfg;
	bdiffparam_t bdp;
	xdemitcb_t ecb, rjecb;

	if (argc < 4) {
		usage(argv[0]);
		return 1;
	}
	malt.priv = NULL;
	malt.malloc = wrap_malloc;
	malt.free = wrap_free;
	malt.realloc = wrap_realloc;
	xdl_set_allocator(&malt);

	do_diff = do_patch = do_bdiff = do_bpatch = do_rabdiff = 0;
	if (!strcmp(argv[i], "--diff")) {
		i++;
		do_diff = 1;
		for (; i < argc; i++) {
			if (strcmp(argv[i], "-C") == 0) {
				if (++i < argc)
					ctxlen = atoi(argv[i]);
			} else
				break;
		}
	} else if (!strcmp(argv[i], "--patch")) {
		i++;
		do_patch = 1;
	} else if (!strcmp(argv[i], "--bdiff")) {
		i++;
		do_bdiff = 1;
		for (; i < argc; i++) {
			if (strcmp(argv[i], "-B") == 0) {
				if (++i < argc)
					bsize = atoi(argv[i]);
			} else
				break;
		}
	} else if (!strcmp(argv[i], "--rabdiff")) {
		i++;
		do_rabdiff = 1;
	} else if (!strcmp(argv[i], "--bpatch")) {
		i++;
		do_bpatch = 1;
	} else {
		usage(argv[0]);
		return 1;
	}
	if (argc - i < 2) {
		usage(argv[0]);
		return 1;
	}

	xpp.flags = 0;
	xecfg.ctxlen = ctxlen;
	bdp.bsize = bsize;
	if (xdlt_load_mmfile(argv[i], &mf1, do_bdiff || do_bpatch) < 0) {

		return 2;
	}
	if (xdlt_load_mmfile(argv[i + 1], &mf2, do_bdiff || do_bpatch) < 0) {

		xdl_free_mmfile(&mf1);
		return 2;
	}
	if (do_diff) {
		ecb.priv = stdout;
		ecb.outf = xdlt_outf;

		if (xdl_diff(&mf1, &mf2, &xpp, &xecfg, &ecb) < 0) {

			xdl_free_mmfile(&mf2);
			xdl_free_mmfile(&mf1);
			return 3;
		}
	} else if (do_bdiff) {
		ecb.priv = stdout;
		ecb.outf = xdlt_outf;
		if (xdl_bdiff(&mf1, &mf2, &bdp, &ecb) < 0) {

			xdl_free_mmfile(&mf2);
			xdl_free_mmfile(&mf1);
			return 4;
		}
	} else if (do_rabdiff) {
		ecb.priv = stdout;
		ecb.outf = xdlt_outf;
		if (xdl_rabdiff(&mf1, &mf2, &ecb) < 0) {

			xdl_free_mmfile(&mf2);
			xdl_free_mmfile(&mf1);
			return 4;
		}
	} else if (do_bpatch) {
		ecb.priv = stdout;
		ecb.outf = xdlt_outf;
		if (xdl_bpatch(&mf1, &mf2, &ecb) < 0) {

			xdl_free_mmfile(&mf2);
			xdl_free_mmfile(&mf1);
			return 5;
		}
	} else if (do_patch) {
		ecb.priv = stdout;
		ecb.outf = xdlt_outf;
		rjecb.priv = stderr;
		rjecb.outf = xdlt_outf;
		if (xdl_patch(&mf1, &mf2, XDL_PATCH_NORMAL, &ecb, &rjecb) < 0) {

			xdl_free_mmfile(&mf2);
			xdl_free_mmfile(&mf1);
			return 6;
		}
	}
	xdl_free_mmfile(&mf2);
	xdl_free_mmfile(&mf1);

	return 0;
}

