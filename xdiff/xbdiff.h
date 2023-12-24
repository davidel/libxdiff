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


#if !defined(XBDIFF_H)
#define XBDIFF_H


#define XDL_BPATCH_HDR_SIZE (4 + 4)
#define XDL_MIN_BLKSIZE 16
#define XDL_INSBOP_SIZE (1 + 4)
#define XDL_COPYOP_SIZE (1 + 4 + 4)



unsigned long xdl_mmb_adler32(mmbuffer_t *mmb);
unsigned long xdl_mmf_adler32(mmfile_t *mmf);



#endif /* #if !defined(XBDIFF_H) */

