#include <stdio.h>
#define A 0x67452301
#define B 0xefcdab89
#define C 0x98badcfe
#define D 0x10325476

unsigned int F(signed int x, signed int y, signed int z) {
    return (x & y) | ((~x) & z);
}
unsigned int G(signed int x, signed int y, signed int z) {
    return (x & z) | ((~z) & y);
}
unsigned int H(signed int x, signed int y, signed int z) {
    return x ^ y ^ z;
}
unsigned int I(signed int x, signed int y, signed int z) {
    return y ^ (x | (~z));
}

unsigned int FF(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int m, int s, unsigned int t) {
    return b + ((a + F(b, c, d) + m + t) <<< s); 
}
unsigned int GG(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int m, int s, unsigned int t) {
    return b + ((a + G(b, c, d) + m + t) <<< s); 
}
unsigned int HH(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int m, int s, unsigned int t) {
    return b + ((a + H(b, c, d) + m + t) <<< s); 
}
unsigned int II(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int m, int s, unsigned int t) {
    return b + ((a + I(b, c, d) + m + t) <<< s); 
}

void calculate1 (unsigned int &a, unsigned int &b, unsigned int &c, unsigned int &d, unsigned int *m) {
    a=FF(a,b,c,d,m[0],7,0xd76aa478);
    b=FF(d,a,b,c,m[1],12,0xe8c7b756);
    c=FF(c,d,a,b,m[2],17,0x242070db);
    d=FF(b,c,d,a,m[3],22,0xc1bdceee);
    a=FF(a,b,c,d,m[4],7,0xf57c0faf);
    b=FF(d,a,b,c,m[5],12,0x4787c62a);
    c=FF(c,d,a,b,m[6],17,0xa8304613);
    d=FF(b,c,d,a,m[7],22,0xfd469501);
    a=FF(a,b,c,d,m[8],7,0x698098d8);
    b=FF(d,a,b,c,m[9],12,0x8b44f7af);
    c=FF(c,d,a,b,m[10],17,0xffff5bb1);
    d=FF(b,c,d,a,m[11],22,0x895cd7be);
    a=FF(a,b,c,d,m[12],7,0x6b901122);
    b=FF(d,a,b,c,m[13],12,0xfd987193);
    c=FF(c,d,a,b,m[14],17,0xa679438e);
    d=FF(b,c,d,a,m[15],22,0x49b40821);
}

void calculate2 (unsigned int &a, unsigned int &b, unsigned int &c, unsigned int &d, unsigned int *m) {
    a=GG(a,b,c,d,m[1],5,0xf61e2562)
    b=GG(d,a,b,c,m[6],9,0xc040b340)
    c=GG(c,d,a,b,m[11],14,0x265e5a51)
    d=GG(b,c,d,a,m[0],20,0xe9b6c7aa)
    a=GG(a,b,c,d,m[5],5,0xd62f105d)
    b=GG(d,a,b,c,m[10],9,0x02441453)
    c=GG(c,d,a,b,m[15],14,0xd8a1e681)
    d=GG(b,c,d,a,m[4],20,0xe7d3fbc8)
    a=GG(a,b,c,d,m[9],5,0x21e1cde6)
    b=GG(d,a,b,c,m[14],9,0xc33707d6)
    c=GG(c,d,a,b,m[3],14,0xf4d50d87)
    d=GG(b,c,d,a,m[8],20,0x455a14ed)
    a=GG(a,b,c,d,m[13],5,0xa9e3e905)
    b=GG(d,a,b,c,m[2],9,0xfcefa3f8)
    c=GG(c,d,a,b,m[7],14,0x676f02d9)
    d=GG(b,c,d,a,m[12],20,0x8d2a4c8a)
}

void calculate3 (unsigned int &a, unsigned int &b, unsigned int &c, unsigned int &d, unsigned int *m) {
    a=HH(a,b,c,d,m[5],4,0xfffa3942)
    b=HH(d,a,b,c,m[8],11,0x8771f681)
    c=HH(c,d,a,b,m[11],16,0x6d9d6122)
    d=HH(b,c,d,a,m[14],23,0xfde5380c)
    a=HH(a,b,c,d,m[1],4,0xa4beea44)
    b=HH(d,a,b,c,m[4],11,0x4bdecfa9)
    c=HH(c,d,a,b,m[7],16,0xf6bb4b60)
    d=HH(b,c,d,a,m[10],23,0xbebfbc70)
    a=HH(a,b,c,d,m[13],4,0x289b7ec6)
    b=HH(d,a,b,c,m[0],11,0xeaa127fa)
    c=HH(c,d,a,b,m[3],16,0xd4ef3085)
    d=HH(b,c,d,a,m[6],23,0x04881d05)
    a=HH(a,b,c,d,m[9],4,0xd9d4d039)
    b=HH(d,a,b,c,m[12],11,0xe6db99e5)
    c=HH(c,d,a,b,m[15],16,0x1fa27cf8)
    d=HH(b,c,d,a,m[2],23,0xc4ac5665)
}

void calculate4 (unsigned int &a, unsigned int &b, unsigned int &c, unsigned int &d, unsigned int *m) {
    a=II(a,b,c,d,m[0],6,0xf4292244)
    b=II(d,a,b,c,m[7],10,0x432aff97)
    c=II(c,d,a,b,m[14],15,0xab9423a7)
    d=II(b,c,d,a,m[5],21,0xfc93a039)
    a=II(a,b,c,d,m[12],6,0x655b59c3)
    b=II(d,a,b,c,m[3],10,0x8f0ccc92)
    c=II(c,d,a,b,m[10],15,0xffeff47d)
    d=II(b,c,d,a,m[1],21,0x85845dd1)
    a=II(a,b,c,d,m[8],6,0x6fa87e4f)
    b=II(d,a,b,c,m[15],10,0xfe2ce6e0)
    c=II(c,d,a,b,m[6],15,0xa3014314)
    d=II(b,c,d,a,m[13],21,0x4e0811a1)
    a=II(a,b,c,d,m[4],6,0xf7537e82)
    b=II(d,a,b,c,m[11],10,0xbd3af235)
    c=II(c,d,a,b,m[2],15,0x2ad7d2bb)
    d=II(b,c,d,a,m[9],21,0xeb86d391)
}

int main() {
	int i, j, k, a = A, b = B, c = C, d = D;
	FILE *fp;
	char filename[100];
	printf("Please input the source file name:\n");
	scanf("%s", filename);
	fp = fopen(filename, "r");
	int size = ftell(fp) * 8, remain = size;
	unsigned int *group;
	while (remain >= 64) {
        remain -= 64;
		fread(group, 4, 16, fp);
        calculate1(a, b ,c ,d, group);
        calculate2(a, b, c, d, group);
        calculate3(a, b, c, d, group);
        calculate4(a, b, c, d, group);
	}
    j = 64 - remain;
    char *remainBuffer;
    fread(remainBuffer, remain, 1, fp);
    char buffer[64];
    for (i = 0; i < 64; ++i) {
        if (i < remainBuffer) buffer[i] = remainBuffer[i];
        if (i == remainBuffer) buffer[i] = 0x80;
        if (i > remainBuffer) buffer[i] = 0;
    }
    group = buffer;
    
}
