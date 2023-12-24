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


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include "xdiff.h"
#include "xtestutils.h"



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
	int i, chmax = 64;
	long size = 1024 * 100;
	double rmod = 0.1;
	xpparam_t xpp;
	xdemitconf_t xecfg;
	bdiffparam_t bdp;
	memallocator_t malt;

	malt.priv = NULL;
	malt.malloc = wrap_malloc;
	malt.free = wrap_free;
	malt.realloc = wrap_realloc;
	xdl_set_allocator(&malt);

	xpp.flags = 0;
	xecfg.ctxlen = 3;
	bdp.bsize = 16;

	for (i = 1; i < argc; i++) {
		if (!strcmp(argv[i], "--size")) {
			if (++i < argc)
				size = atol(argv[i]);
		} else if (!strcmp(argv[i], "--rmod")) {
			if (++i < argc)
				rmod = atof(argv[i]);
		} else if (!strcmp(argv[i], "--ctxlen")) {
			if (++i < argc)
				xecfg.ctxlen = atol(argv[i]);
		} else if (!strcmp(argv[i], "--chmax")) {
			if (++i < argc)
				chmax = atoi(argv[i]);
		}
	}

	srand(time(NULL));
	for (i = 0;; i++) {
		fprintf(stderr, "Running TEXT test : %d ... ", i);
		if (xdlt_auto_regress(&xpp, &xecfg, size, rmod, chmax) < 0) {

			fprintf(stderr, "FAIL\n");
			break;
		} else {

			fprintf(stderr, "OK\n");
		}

		fprintf(stderr, "Running BIN  test : %d ... ", i);
		if (xdlt_auto_binregress(&bdp, size, rmod, chmax) < 0) {

			fprintf(stderr, "FAIL\n");
			break;
		} else {

			fprintf(stderr, "OK\n");
		}

		fprintf(stderr, "Running RBIN  test : %d ... ", i);
		if (xdlt_auto_rabinregress(size, rmod, chmax) < 0) {

			fprintf(stderr, "FAIL\n");
			break;
		} else {

			fprintf(stderr, "OK\n");
		}

		fprintf(stderr, "Running MBIN  test : %d ... ", i);
		if (xdlt_auto_mbinregress(&bdp, size, rmod, chmax, 32) != 0) {

			fprintf(stderr, "FAIL\n");
			break;
		} else {

			fprintf(stderr, "OK\n");
		}
	}

	return 0;
}

