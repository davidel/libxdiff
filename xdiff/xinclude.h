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


#if !defined(XINCLUDE_H)
#define XINCLUDE_H


#if defined(HAVE_WINCONFIG_H)
#include "winconfig.h"
#endif /* #if defined(HAVE_CONFIG_H) */

#if defined(HAVE_CONFIG_H)
#include "config.h"
#endif /* #if defined(HAVE_CONFIG_H) */

#if defined(HAVE_STDIO_H)
#include <stdio.h>
#endif /* #if defined(HAVE_STDIO_H) */

#if defined(HAVE_STDLIB_H)
#include <stdlib.h>
#endif /* #if defined(HAVE_STDLIB_H) */

#if defined(HAVE_UNISTD_H)
#include <unistd.h>
#endif /* #if defined(HAVE_UNISTD_H) */

#if defined(HAVE_STRING_H)
#include <string.h>
#endif /* #if defined(HAVE_STRING_H) */

#if defined(HAVE_LIMITS_H)
#include <limits.h>
#endif /* #if defined(HAVE_LIMITS_H) */



#include "xmacros.h"
#include "xmissing.h"
#include "xdiff.h"
#include "xtypes.h"
#include "xutils.h"
#include "xadler32.h"
#include "xprepare.h"
#include "xdiffi.h"
#include "xemit.h"
#include "xbdiff.h"



#endif /* #if !defined(XINCLUDE_H) */

