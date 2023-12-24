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



#if !defined(HAVE_MEMCHR)

void *memchr(void const *p, int c, long n) {
	char const *pc = p;

	for (; n; n--, pc++)
		if (*pc == (char) c)
			return pc;
	return NULL;
}

#endif /* #if !defined(HAVE_MEMCHR) */


#if !defined(HAVE_MEMCMP)

int memcmp(void const *p1, void const *p2, long n) {
	char const *pc1 = p1, *pc2 = p2;

	for (; n; n--, pc1++, pc2++)
		if (*pc1 != *pc2)
			return *pc1 - *pc2;
	return 0;
}

#endif /* #if !defined(HAVE_MEMCMP) */


#if !defined(HAVE_MEMCPY)

void *memcpy(void *d, void const *s, long n) {
	char *dc = d;
	char const *sc = s;

	for (; n; n--, dc++, sc++)
		*dc = *sc;
	return d;
}

#endif /* #if !defined(HAVE_MEMCPY) */


#if !defined(HAVE_MEMSET)

void *memset(void *d, int c, long n) {
	char *dc = d;

	for (; n; n--, dc++)
		*dc = (char) c;
	return d;
}

#endif /* #if !defined(HAVE_MEMSET) */


#if !defined(HAVE_STRLEN)

long strlen(char const *s) {
	char const *tmp;

	for (tmp = s; *s; s++);
	return (long) (s - tmp);
}

#endif /* #if !defined(HAVE_STRLEN) */

