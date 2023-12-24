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


#if !defined(XTESTUTILS_H)
#define XTESTUTILS_H



#define DBL_RAND() (((double) rand()) / (1.0 + (double) RAND_MAX))



int xdlt_dump_mmfile(char const *fname, mmfile_t *mmf);
int xdlt_load_mmfile(char const *fname, mmfile_t *mf, int binmode);
int xdlt_do_diff(mmfile_t *mf1, mmfile_t *mf2, xpparam_t const *xpp,
		 xdemitconf_t const *xecfg, mmfile_t *mfp);
int xdlt_do_patch(mmfile_t *mfo, mmfile_t *mfp, int mode, mmfile_t *mfr);
int xdlt_do_regress(mmfile_t *mf1, mmfile_t *mf2, xpparam_t const *xpp,
		    xdemitconf_t const *xecfg);
long xdlt_gen_line(char *buf, long msize);
int xdlt_create_file(mmfile_t *mf, long size);
int xdlt_change_file(mmfile_t *mfo, mmfile_t *mfr, double rmod, int chmax);
int xdlt_auto_regress(xpparam_t const *xpp, xdemitconf_t const *xecfg, long size,
		      double rmod, int chmax);
int xdlt_do_bindiff(mmfile_t *mf1, mmfile_t *mf2, bdiffparam_t const *bdp, mmfile_t *mfp);
int xdlt_do_rabdiff(mmfile_t *mf1, mmfile_t *mf2, mmfile_t *mfp);
int xdlt_do_binpatch(mmfile_t *mf, mmfile_t *mfp, mmfile_t *mfr);
int xdlt_do_binregress(mmfile_t *mf1, mmfile_t *mf2, bdiffparam_t const *bdp);
int xdlt_do_rabinregress(mmfile_t *mf1, mmfile_t *mf2);
int xdlt_auto_binregress(bdiffparam_t const *bdp, long size,
			 double rmod, int chmax);
int xdlt_auto_rabinregress(long size, double rmod, int chmax);
int xdlt_auto_mbinregress(bdiffparam_t const *bdp, long size,
			  double rmod, int chmax, int n);


#endif /* #if !defined(XTESTUTILS_H) */

