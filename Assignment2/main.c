#include <stdio.h>
#include "toylib.h"


int main()
{
	char string[]="Shrihari Gajanan Danawe";
	int noc=printUpperString(string);
	printf("Return value of printUpperString is %d\n",noc);
	int n;
	printf("Enter an integer : ");
	scanf("%d",&n);
	int hexi=printHexInteger(n);
	printf("Return value of printHexInteger is %d\n",hexi);
	float f;
	printf("Enter a floting number : ");
	scanf("%f",&f);
	int floatnumber=printFloat(f);
	printf("Return value of printFloat is %d\n",floatnumber);
	float fppp;
	int readfloat=readFloat(&fppp);
	printf("Return value of readFloat is %d and the value read is %f\n",readfloat,fppp);
	int hex;
	int readhexint=readHexInteger(&hex);
	printf("Return value of readhexinteger is %d and the value read is %d\n",readhexint,hex);
	return 0;
}