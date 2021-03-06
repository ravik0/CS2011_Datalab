/* 
 * CS:APP Data Lab 
 * 
 * Ravi Kirschner, 392108009
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

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


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
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
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
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/* 
 * oddBits - return word with all odd-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int oddBits(void) {
	//want 0xAAAAAAAA
	int a = 0xAA; //have what we want
	a = (a << 8) | a; //this moves a to 0xAA00 and ors on original A, to get 0xAAAA
	return (a << 16) | a; //repeat same process, create 0xAAAA0000 and or with 0x0000AAAA
}
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
	//for the minimum twos compliment (0x80000000) if you add it to itself, you get 0.
	//therefore, if you not that, you get one. this works for everything but 0x0, because that has the same property
	//use the double not to get rid of that, because !!0x0 = 0, so if you get 0x0 then the answer is forced to 0
	//for any nonzero number, !!x = 1, so anding it does nothing. that gets you !(x+x)&!!x
	//demorgans law states that & = !(!a|!b) so can rewrite. if there is a !!, replace with nothing.
	return !((x+x)|!x);
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
	//from ece2029: XOR is (a|b)&(~a|~b)
	//from stats: or is ~(~a&~b) (demorgans)
	//so implementation is (~(~a&~b)&~(a&b))
	return (~(~x&~y)&~(x&y));
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	int cond = !!x; //if x is 0, then take z. if x is anything else, take y.
	int choose = ~cond+1; //if cond is 0, you get 0x0. if cond is 1, you get 0xFFFFFFFF
	//if cond is 0, choose is 0x0, so need to invert that to get z. if cond is 1, choose is 0xFFFFFFFF, so don't invert that for y.
	//inverting 0x0 = 0xFFFFFFFF and inverting 0xFFFFFFFFF = 0x0, so only gets one or the other.
	return (choose & y) | (~choose & z);
}
/* 
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4 
 */
int greatestBitPos(int x) {
	int invertedX;
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 3;
	x |= x >> 4;
	x |= x >> 5;
	x |= x >> 6;
	x |= x >> 7;
	x |= x >> 8;
	x |= x >> 9;
	x |= x >> 10;
	x |= x >> 11;
	x |= x >> 12;
	x |= x >> 13;
	x |= x >> 14;
	x |= x >> 15;
	//this forces all bits to the right of the most significant 1 to be a 1.
	invertedX = ~x; //by inverting x, all bits that were now 0s are 1s. So everything to the right of the most significant 1 is 0.
	invertedX = invertedX >> 1; //shift right so that there is now exactly 1 set of 1s that align
	return (x & invertedX)|(x & (1 << 31)); //because of overflow, 0x80000000 doesn't work well. so we just have to or it in.
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    int negative = x >> 31; //gives sign bit for 31
    int twok = (1 << n) + ~0; //gets 2^n-1, via lecture. ~0 is -1.
    int and = negative & twok; //if x negative, then negative is all 1s and you just have the 2^n-1. if x positive, the and is 0.
    int dividend = x + and; //add value to get a number divisible by n
    return dividend >> n; //shift by n to divide by 2^n
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
	//because this is signed, any negative number has 1 in the MSB
	//therefore, shift right 31 times to get that 1 in the LSB. then negate it
	//if there was a 1 there, it is now 0. if there was a 0 there (meaning >=0), it's 1
	return !(x>>31);
}
/*
 * satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
 *   Examples: satMul2(0x30000000) = 0x60000000
 *             satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
 *             satMul2(0x60000000) = 0x80000000 (saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int satMul2(int x) {
	int sign = x >> 31; //sign bit
	int overflow_determine = (x << 1) >> 31; //bit next to the sign bit, determines whether overflow
	int overflow_condition = sign^overflow_determine; //if this is 0xFFFFFFFFF, there is possible overflow
	int saturation_value = overflow_determine^(1 << 31); //if 31st bit is 1, then nonsign_msb is all 1s, xor will create 0x7FFFFFFF
	//if 31st bit is 0, then nonsign_msb is all 0s, xor will create 0x80000000
	int multiplied = x << 1; //multiply x by 2
	return (overflow_condition&saturation_value) | ((~overflow_condition)&multiplied);
	//if overflow condition is all 1s, then you get saturation value. otherwise get the multiplied value
}
/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {
	int signx = (x >> 31) & 0x1; //x sign
	int signy = (y >> 31) & 0x1; //y sign
	int diff = (x + (~y+1)); //x-y
	//there are 3 cases:
	//1. x < 0, y >= 0
	//2. x >= 0, y < 0
	//3. same sign
	int case1  = (signx) & ((!signy) | !y);
	int case2 = ((!signx) | !x) & (signy);
	int case3 = (diff >> 31) & !case2; //if diff is negative and we're not dealing with case2, then same sign
	return case1 | case3; //we dont need to put case2 because it will always be 0 if those numbers line up.

}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
	int zero = 0x30; //constant declaration
	int nine = 0x3a; //constant declaration
	//if x is between 0x30 and 0x39, then the first term should be >=0.
	//therefore, if we shift to the right by 31 we get the sign bit (0) and not to get 0x1.
	//if x is between 0x30 and 0x39, then the second term should be <0.
	//if we shift to the right by 31, we get sign bit (1) and then & with the other one.
	//the reason we want <0 not <=0 is because we want the sign bit to always be a 1. if it was <= 0, we have edge case of 0x39 returning a zero there.
	return (!((x+(~zero+1)) >> 31)) & ((x+(~nine+1)) >> 31);

}
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int trueThreeFourths(int x)
{
	int remainder = x & 0x3; //when dividing by 4, lose first 2 bits
	int sign = (x >> 31) & remainder; //sign bit and first two bits of x.
	//need a sign related argument because negative division doesn't auto-round to 0.

	x = x >> 2; //divide by 4
	x = x + (x << 1); //multiply by 3

	//add 3/4 of the remainder, incrementing by sign if needed
	return x + ((remainder + (remainder << 1) + sign) >> 2);
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
	int ret = 0x0; //return value
	int tester = x; //we'll be testing various parts of x in this
	//the premise is that, in 32-bit, you have 2^(16+8+4+2+1) numbers.
	//we want a number for each of those, 16, 8, 4, 2, 1
	tester = !!(x >> 16); //if there is a 1 here, that means it's divisble by
	ret = ret + (tester << 4); //we shift to the right by 4 to account for the fact that this is the 4th number here
	//now we look at 8
	tester = !!(x >> (8 + ret)); //we have to add ret to 8 because we need to take into account the offset incase ret is nonzero
	ret = ret + (tester << 3); //third bit place
	//the same for the others
	tester = !!(x >> (4 + ret));
	ret = ret + (tester << 2);

	tester = !!(x >> (2 + ret));
	ret = ret + (tester << 1);

	tester = !!(x >> (1 + ret));
	ret = ret + tester;

	return ret; //finally return


	return ret;
}
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
	int sign_bit = 1 << 31; //creates constant of 0x80000000
	int ret = uf ^ sign_bit; //if number, this is the result. this just swaps the sign bit. 0^1 = 1, 1^1 = 0
	//NaN is when all exponent bits are 1, and fraction all 0s
	int isNan = uf << 1; //get rid of sign bit. want 0xFF000000 to be NaN.
	if(isNan > 0xFF000000) ret = uf;
	return ret;
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
	int sign = x & (1 << 31); //sign bit
	int e = 158; //exponent val, bias already added
	int frac; //the frac value

	if(x == 0) return 0; //if x is 0, float 0 is just 0. (This is to not have to deal w/ 0 case in while loop)
	if(x < 0) x = ~x + 1; //if x is negative, make it positive. only thing that changes in neg vs pos float rep is sign bit.

	while (((x >> 31) & 0x1) != 0x1) {
		e--;
		x = x << 1;
	} //find where the decimal should go by making sure there's a 1 in the MSB pos.

	frac = (x & ~(1 << 31)) >> 8; //take everything but sign bit and shift it to the right by 8 bits, make room for e.

	//if exponent has a leading 0 as well as fraction being odd or the rest of exponent being nonzero, add 1.
	if(((frac & 1) || (x & 0x7F) > 0) && (x & 0x80)) frac+=1;

	return sign + (e << 23) + frac;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
	int sign = uf & (1 << 31); //sign bit isolated
	int e = ((uf << 1) >> 24) << 23; //need all the shifting to put the exponent into the 8 bits it should occupy
	int frac = (uf << 9) >> 9; //same here, need to get frac where it belongs

	//there are 2 special cases:
	//case 1: exponent is 0x7F800000 which is NaN
	//case 2: exponent is 0
	//to handle case 1, simply return uf
	if(e == 0x7F800000) return uf;
	//to handle case 2, we shift frac over by 1 (multiply that by 2)
	else if (e == 0) return (frac << 1) + sign + e;
	//otherwise, we just add 1 to the exponent
	else e+=(1 << 23);
	return frac + sign + e;
}
