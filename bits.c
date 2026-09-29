/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int a, int b) {
    return ~(~a | ~b);
}

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int a1, int a2) {
    return ~(~a1 & ~a2) & ~(a1 & a2);
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int aa, int bb) {
    if (!aa && !bb) return 1;
    if (!aa ^ !bb) return 0;
    return !((aa>>31) ^ (bb>>31));
}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int aa){
    int r=0;
    int c,s;
    c=(aa>>16)>0;
    s=c<<4;
    r = r | s;
    aa = aa >> s;

    c=(aa>>8)>0;
    s=c<<3;
    r = r | s;
    aa = aa >> s;

    c=(aa>>4)>0;
    s=c<<2;
    r = r | s;
    aa = aa >> s;

    c=(aa>>2)>0;
    s=c<<1;
    r = r | s;
    aa = aa >> s;

    c=(aa>>1)>0;
    r = r | c;
    return r;
}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x, int n, int m) {
    int s1=n<<3;
    int s2=m<<3;
    int b1=(x>>s1) & 0xFF;
    int b2=(x>>s2) & 0xFF;
    int k1=0xFF<<s1;
    int k2=0xFF<<s2;
    x = x & ~(k1 | k2);
    x = x | (b1<<s2) | (b2<<s1);
    return x;
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v) {
    unsigned o=0;
    for(int i=32;i;i--){
        o=(o<<1) | (v & 1);
        v=v>>1;
    }
    return o;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x, int n) {
    int m=~(1<<31>>n<<1);
    return (x>>n) & m;
}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int a) {
    int c=0;
    int t,cc,ss;

    t=a>>16;
    cc=!~t;
    ss=cc<<4;
    c=c+ss;
    a=a<<ss;

    t=a>>24;
    cc=!~t;
    ss=cc<<3;
    c=c+ss;
    a=a<<ss;

    t=a>>28;
    cc=!~t;
    ss=cc<<2;
    c=c+ss;
    a=a<<ss;

    t=a>>30;
    cc=!~t;
    ss=cc<<1;
    c=c+ss;
    a=a<<ss;

    t=a>>31;
    cc=!~t;
    ss=cc;
    c=c+ss;
    a=a<<ss;

    t=a>>31;
    cc=!~t;
    ss=cc;
    c=c+ss;

    return c;
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {
    unsigned s=x&0x80000000;
    unsigned ax=x;
    if(x<0) ax=-x;
    if(ax==0) return 0;
    int e=31;
    while(!(ax>>e)) e--;
    unsigned ex=(e+127)<<23;
    unsigned f=0;
    if(e<24){
        f=(ax<<(23-e))&0x7FFFFF;
    } else {
        int sh=e-23;
        f=(ax>>sh)&0x7FFFFF;
        unsigned p=1<<sh;
        unsigned mk=p-1;
        unsigned h=p>>1;
        unsigned r=ax&mk;
        if(r>h){
            f++;
        }else if(r==h){
            if(f & 1) f++;
        }
        if(f==0x800000){
            ex+=1<<23;
            f=0;
        }
    }
    return s | ex | f;
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {
    unsigned s=uf&0x80000000;
    unsigned e=(uf>>23)&0xFF;
    unsigned f=uf&0x7FFFFF;
    if(e==0xFF){
        return uf;
    }
    if(e==0){
        if(f==0) return uf;
        f=f<<1;
        if(f&0x800000){
            e=1;
            f=f&0x7FFFFF;
        }
    }else{
        e=e+1;
        if(e==0xFF){
            return s | 0x7F800000;
        }
    }
    return s | (e<<23) | f;
}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    unsigned s=uf2>>31;
    unsigned e=(uf2>>20) & 0x7FF;
    unsigned fh=uf2 & 0xFFFFF;
    unsigned fl=uf1;
    int ee,rs;
    unsigned mh, ml, res;
    if(!(e-0x7FF)){
        return 0x80000000;
    }
    if(!e){
        return 0;
    }
    ee=e-1023;
    if(ee<0){
        return 0;
    }
    if(ee>=31){
        return 0x80000000;
    }
    rs=52-ee;
    mh=(1<<20) | fh;
    ml=fl;
    if(rs>=32){
        res=mh>>(rs-32);
    }else{
        res=(mh<<(32-rs)) | (ml>>rs);
    }
    if(s){
        res=-res;
    }
    return res;
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x){
    if(x>=128){
        return 0x7F800000;
    }
    if(x<-149){
        return 0; 
    }
    if(x>=-126){
        return (x+127)<<23;
    }else{
        return 1<<(x+149);
    }
}