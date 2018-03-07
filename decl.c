#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TMin INT_MIN
#define TMax INT_MAX

#include "btest.h"
#include "bits.h"

test_rec test_set[] = {
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
// bit manip puzzles
 {"orWithoutOr", (funct_t) orWithoutOr, (funct_t) test_bitOr, 2, "& ~", 8, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"wordWithEveryThird", (funct_t) wordWithEveryThird, (funct_t) test_thirdBits, 0,
    "! ~ & ^ | + << >>", 8, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
{"swapTwoBytes", (funct_t) swapTwoBytes, (funct_t) test_swapTwoBytes, 3,
     "! ~ & ^ | + << >>", 25, 2,
    {{TMin, TMax},{0,3},{0,3}}},
 {"hasAnEvenBitSet", (funct_t) hasAnEvenBitSet, (funct_t) test_hasAnEvenBitSet, 1,
    "! ~ & ^ | + << >>", 12, 2,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"shiftLogically", (funct_t) shiftLogically, (funct_t) test_shiftLogically,
   2, "! ~ & ^ | + << >>", 20, 3,
  {{TMin, TMax},{0,31},{TMin,TMax}}},
// two's comp puzzles
 {"isShortSized", (funct_t) isShortSized, (funct_t) test_isShortSized, 1,
    "! ~ & ^ | + << >>", 8, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"isMaxTC", (funct_t) isMaxTC, (funct_t) test_isMaxTC, 1, "! ~ & ^ | +", 10, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"subtractOne", (funct_t) subtractOne, (funct_t) test_subtractOne, 0,
    "! ~ & ^ | + << >>", 2, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"fitsInNBits", (funct_t) fitsInNBits, (funct_t) test_fitsInNBits, 2,
    "! ~ & ^ | + << >>", 15, 2,
  {{TMin, TMax},{1,32},{TMin,TMax}}},
 {"negate", (funct_t) negate, (funct_t) test_negate, 1,
    "! ~ & ^ | + << >>", 5, 2,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"getSignBit", (funct_t) getSignBit, (funct_t) test_getSignBit, 1, "! ~ & ^ | + << >>", 10, 2,
     {{-TMax, TMax},{TMin,TMax},{TMin,TMax}}},
 {"isLessThan", (funct_t) isLessThan, (funct_t) test_isLessThan, 2,
    "! ~ & ^ | + << >>", 24, 3,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"logicalNot", (funct_t) logicalNot, (funct_t) test_logicalNot, 1,
    "~ & ^ | + << >>", 12, 4,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
// floating point (advanced)
 {"float_neg", (funct_t) float_neg, (funct_t) test_float_neg, 1,
    "$", 10, 2,
     {{1, 1},{1,1},{1,1}}},
 {"float_i2f", (funct_t) float_i2f, (funct_t) test_float_i2f, 1,
    "$", 30, 4,
     {{1, 1},{1,1},{1,1}}},
  {"", NULL, NULL, 0, "", 0, 0,
   {{0, 0},{0,0},{0,0}}}
};
