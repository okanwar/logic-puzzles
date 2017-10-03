/* 
 * COMP280 (Intro to Computer Systems) - Project 02
 * 
 * Author: ENTER YOUR NAME AND USD ID HERE
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
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
/* 
 * orWithoutOr - x|y using only ~ and & 
 *   Example: orWithoutOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int orWithoutOr(int x, int y) {
  return ~(~x & ~y);//returns x or y, while leaving the possibility for x and y 
}
/* 
 * wordWithEveryThird - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int wordWithEveryThird(void) {
   int x = 0x49;//initializes pattern template
   int y = (x << 9);// shifts the pattern to first bit of third byte
   int z = y + x; //copies pattern
   return (z << 18) + z;
}
/* 
 * swapTwoBytes - swaps the nth byte and the mth byte
 *  Examples: swapTwoBytes(0x12345678, 1, 3) = 0x56341278
 *            swapTwoBytes(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int swapTwoBytes(int x, int n, int m) {
    int nShift = n << 3; //multiplies by 8
	int mShift = m << 3;
	int copy = 0xFF; //byte copy and paste method
	int nByte = (copy << nShift) & x; //bytes held here to be swapped
	int mByte = (copy << mShift) & x;
	//bytes stored here that won't be swapped
	int shiftLast = ((~((copy << nShift) | (copy << mShift))) & x); //bytes stored here that
	//won't be swapped
	nByte = (nByte >> nShift) & copy; //bytes placed for swap and swaps made
	nByte <<= mShift;
	mByte = (mByte >> mShift) & copy;
	mByte <<= nShift;
	return shiftLast | mByte | nByte;
}
/* 
 * hasAnEvenBitSet - return 1 if any even-numbered bit in word set to 1
 *   Examples hasAnEvenBitSet(0xA) = 0, hasAnEvenBitSet(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int hasAnEvenBitSet(int x) {
	//int y is a 32 bit mask using 0x55 bytes
	//0x5 has binary form 0101, which will be true for all even bits
	int y = (0x55 + (0x55<<8) + (0x55<<16) + (0x55<<24));
	//x&y returns string of zeroes if there are no even bits
	//x&y returns a number if there are even bits, double ! necessary to return zero
	return !(!(x&y));
}
/* 
 * shiftLogically - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: shiftLogically(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int shiftLogically(int x, int n) {
	int mask = 0x80; //Uses a mask like operator to evaluate bit values
	mask <<= 24;     //to zero out any ones that come from expanded sign
	mask &= x;
	mask >>= n;
	mask <<= 1;  
	return (mask ^ (x >>= n));
}
// two's comp puzzles
/* 
 * isShortSized - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: isShortSized(33000) = 0, isShortSized(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int isShortSized(int x) {
	int y = x << 16;//drops all significant bits 
	int z = y >> 16;//z represents if x cannot be represented by 16-bit
					//two's complement integer
    return !(x^z);//returns 1 if x can be represented by 16-bit
				  //two's complement integer and zero otherwise 
}
/*
 * isMaxTC - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isMaxTC(int x) {
	int y = x + 1;//if x is max#, then x + 1 will wrap around to give min number
	// Taking y ^ x will give you a bit string of 1111
	// Negating that gives you a bit string of all 0.
	// the final variable will return 1 for max
	// The +!y is needed for the case of inputting -1 
	// Adding one will produce 0000
	// doing ^(y with x) will again produce 0000.
	// This will incorrectly return 1 for -1 Adding !y gives us a correct final result of 0.
	return !(~((y)^x)+!y);
}
/* 
 * subtractOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int subtractOne(void) {
  return ~0x00;//inverts the bits of 0000 0000 to get -1
}
/* 
 * fitsInNBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsInNBits(5,3) = 0, fitsInNBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsInNBits(int x, int n) {
	int shiftFirst = (~x & (x >> 0x1F)); //inverse of x and shifts it right by 31 bits
	int shiftSecond = (x & ~(x >> 0x1F));//shiftSecond initalized to x and (not)x shifted 31
	return !(((shiftFirst) + shiftSecond) >> (n + ~0));//shifted right by (n + 1), but negated
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 0x01;//inverse of x + 1	
}
/* 
 * getSignBit - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: getSignBit(130) = 1
 *            getSignBit(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int getSignBit(int x) {
    int sign = x >> 31; // goes to sign bit of x 
	int signInverse = (~x + 1) >> 31; //goes to sign bit of negative x
	return (sign | (signInverse & 1));
}
/* 
 * isLessThan - if x < y  then return 1, else return 0 
 *   Example: isLessThan(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessThan(int x, int y) {
  return 2;
}
/* 
 * logicalNot - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNot(3) = 0, logicalNot(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNot(int x) {
  return 2;
}
// floating point (advanced)
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
 return 2;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  return 2;
}
