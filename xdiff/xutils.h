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


#if !defined(XUTILS_H)
#define XUTILS_H



long xdl_bogosqrt(long n);
int xdl_emit_diffrec(char const *rec, long size, char const *pre, long psize,
		     xdemitcb_t *ecb);
int xdl_mmfile_outf(void *priv, mmbuffer_t *mb, int nbuf);
int xdl_cha_init(chastore_t *cha, long isize, long icount);
void xdl_cha_free(chastore_t *cha);
void *xdl_cha_alloc(chastore_t *cha);
void *xdl_cha_first(chastore_t *cha);
void *xdl_cha_next(chastore_t *cha);
long xdl_guess_lines(mmfile_t *mf);
unsigned long xdl_hash_record(char const **data, char const *top);
unsigned int xdl_hashbits(unsigned int size);
int xdl_num_out(char *out, long val);
long xdl_atol(char const *str, char const **next);
int xdl_emit_hunk_hdr(long s1, long c1, long s2, long c2, xdemitcb_t *ecb);



#endif /* #if !defined(XUTILS_H) */

