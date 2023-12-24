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


#define XDL_MERGE3_BLKSIZE (1024 * 8)
#define XDL_MERGE3_CTXLEN 3



int xdl_merge3(mmfile_t *mmfo, mmfile_t *mmf1, mmfile_t *mmf2, xdemitcb_t *ecb,
	       xdemitcb_t *rjecb) {
	xpparam_t xpp;
	xdemitconf_t xecfg;
	xdemitcb_t xecb;
	mmfile_t mmfp;

	if (xdl_init_mmfile(&mmfp, XDL_MERGE3_BLKSIZE, XDL_MMF_ATOMIC) < 0) {

		return -1;
	}

	xpp.flags = 0;

	xecfg.ctxlen = XDL_MERGE3_CTXLEN;

	xecb.priv = &mmfp;
	xecb.outf = xdl_mmfile_outf;

	if (xdl_diff(mmfo, mmf2, &xpp, &xecfg, &xecb) < 0) {

		xdl_free_mmfile(&mmfp);
		return -1;
	}

	if (xdl_patch(mmf1, &mmfp, XDL_PATCH_NORMAL, ecb, rjecb) < 0) {

		xdl_free_mmfile(&mmfp);
		return -1;
	}

	xdl_free_mmfile(&mmfp);

	return 0;
}

