/* 
 * <Jessica Du jd4744>
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
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  // formed by logic table and definition of xor

  int r = (~(x & y)) & (~(~x) & (~y));
  
  return r;
	
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  //we shift the 1 all the way to the left so that it is followed by 31 0's
  int min = 1 << 31;
  return min;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 2
 */
int isTmax(int x) {
  /* if x is -1, max is 1, or else max will be 0, then adding 1, flipping the bits, and
  * the xor operation will make x max become - if x is the maximum 2s complement
  */
  int max = !(~(x ^ (x + 1)));
  return max;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  /* create all odd numbered bits, which is 0xAAAAAAAA (allOdd), then 
  * return 1 if x matches conditions 
  */ 
  int allOdd = 0xAA + (0xAA << 8) + (0xAA << 16) + (0xAA << 24);
  int a = !((x & allOdd) ^ allOdd);

  return a;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  //flip bits and add 1

  return ~x+1;
}
//3
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
  /* create upper and lower bounds so that if anything less than lower bound or
  * greater than upper bound is added, the result will become negative. then, 
  * add x and check the sign bits for both upper and lower bound. if 
  * the result is negative, then 0x30 <= x <= 0x39 is not true
  */

  int sign = 1 << 31;
  int lower = ~0x30;
  int upper = ~0x39;

  lower = sign & (lower + x + 1) >> 31;
  upper = sign & (upper + x) >> 31; 
  
  return !(lower | upper);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  /* make x either all 0's or 1's, then if x is true, y will execute.
  * if x is false, z will execute
  */
  int a = (!x + ~0x00);

  return (a & y) | (~a & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /* xsign and ysign copies the significant bit to all places, then returns 0 if
  * positive and 1 if negative. then, z checks if x is less than y and whether
  * the signs are the same or not 
  */

  int xsign = (x >> 31) & 1;
  int ysign = (y >> 31) & 1;
  int z = (!(xsign ^ ysign)) & (((x + ~y) >> 31) & 1);

  return z | ((!ysign) & xsign);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  /* zero is the only number that is the same complemented when normal and inversed
  * so, we check the complement and inverse complement of x, as well as the
  * sign of the first bit
  */

  return (((~(~x + 1)) & (~x)) >> 31) & 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  /* create ints for sign, bit 16, bit 8, bit 4, bit 2, bit 1, and bit 0. then we will invert
  * negative numbers and find log2(n). we add 1 to the final result in order to represent
  * the sign. 
  */

  int sign, b0, b1, b2, b4, b8, b16;

  sign = x >> 31;
  x = (sign & ~x) | (~sign & x);

  b16 = !!(x >> 16) << 4;
  x = x >> b16;

  b8 = !!(x >> 8) << 3;
  x = x >> b8;
  
  b4 = !!(x >> 4) << 2;
  x = x >> b4;

  b2 = !!(x >> 2) << 1;
  x = x >> b2;

  b1 = !!(x >> 1);
  x = x >> b1;
  
  b0 = x;

  return b16 + b8 + b4 + b2 + b1 + b0 + 1;
}
//float
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
  /* three cases:
  * uf = +-0
  * when argument is NaN
  * when the value is non-zero but very small
  * if none of these cases apply to the float value, then add 1 to the exp
  */

  if(uf == 0 || uf == 0x80000000)
	return uf;

  if(((uf >> 23) & 0xff) == 0xfff)
	return uf;

  if(((uf >> 23) & (1 >> 31)) | (uf << 1))
	return (uf & (1 >> 31)) | (uf << 1);

  return uf + (1 << 23);
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
  /* create variables for the float sign, negative, exp value, bias, and frac
  * then three cases
  * base case when !x is true, return 0
  * when x is the minimum value, return minimum value + mantissa
  * we will also check the sign, so that if it is negative, we negate
  * then, while  
  */ 
  int sign = x >> 31;
  int minus = 1 << 31;
  int exp = 21;
  int bias = 127;
  int frac;

  if(!x)
	return 0;

  if(x == minus)
	return minus + ((exp + bias) << 23);

  if(sign)
	x = ~x + 1;

  while(!(x & minus)){
 	x <<= 1;
	exp -= 1;
  }

  frac = (((~minus) & x) >> 8);

  if(x & 0x80 && ((frac & 1) || ((x & 0x7f) > 0)))
	frac++;
  return sign + ((exp + bias) << 23) + frac;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  /* create unsigned values for sign, exp, frac, bias, and the return result, which 
  * we set equal to frac. 
  * first if case is for Nan and infinity, which will return 0x80000000u.
  * the next if case is for denormalized cases and normalized exp that is less
  * than the bias cases, which will return 0x0.
  * then exp -= bias is for normalizing cases.
  * the next if case is for overflow, which will return 0x80000000u since
  * it is out of range.
  * then, we get the integer result of corresponding bits after shift
  * for normalized cases, we add 1 << exp, and if the sign is 1, we change it
  */

  unsigned sign = uf >> 31;
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned frac = (uf & 0x7FFFFF);
  unsigned bias = 0x7F;
  unsigned result = frac;

  if(exp == 0xFF)
	return 0x80000000u;

  if(exp < bias)
	return 0x0;

  exp -= bias;

  if(exp >= 31)
	return 0x80000000u;

  if(exp > 22)
	result = frac << (exp - 23);

  else
	result = frac >> (23 - exp);

  result += 1 << exp;

  if(sign)
	result = -result;

  return result;
}
