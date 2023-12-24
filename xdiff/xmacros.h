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


#if !defined(XMACROS_H)
#define XMACROS_H


#define XDL_MIN(a, b) ((a) < (b) ? (a): (b))
#define XDL_MAX(a, b) ((a) > (b) ? (a): (b))
#define XDL_ABS(v) ((v) >= 0 ? (v): -(v))
#define XDL_ISDIGIT(c) ((c) >= '0' && (c) <= '9')
#define XDL_ADDBITS(v, b) ((v) + ((v) >> (b)))
#define XDL_MASKBITS(b) ((1UL << (b)) - 1)
#define XDL_HASHLONG(v, b) (XDL_ADDBITS((unsigned long) (v), b) & XDL_MASKBITS(b))
#define XDL_PTRFREE(p) do { if (p) { xdl_free(p); (p) = NULL; } } while (0)
#define XDL_RECMATCH(r1, r2) ((r1)->size == (r2)->size && memcmp((r1)->ptr, (r2)->ptr, (r1)->size) == 0)
#define XDL_LE32_PUT(p, v) do { \
	unsigned char *__p = (unsigned char *) (p); \
	*__p++ = (unsigned char) (v); \
	*__p++ = (unsigned char) ((v) >> 8); \
	*__p++ = (unsigned char) ((v) >> 16); \
	*__p = (unsigned char) ((v) >> 24); \
} while (0)
#define XDL_LE32_GET(p, v) do { \
	unsigned char const *__p = (unsigned char const *) (p); \
	(v) = (unsigned long) __p[0] | ((unsigned long) __p[1]) << 8 | \
		((unsigned long) __p[2]) << 16 | ((unsigned long) __p[3]) << 24; \
} while (0)


#endif /* #if !defined(XMACROS_H) */

