// Test Expressions
int test = 1;
int main () {
	int a=1, b=2;
	int d=1;
	int c[15];
	c[0]=1;
	c[1]=(a+b);
	c[2]=a+b;
	c[3]=a*b;
	c[4]=a++;
	c[5]=--b;
	c[6]=!b;
	c[7]=a/b;
	c[8]=a%b;
	c[9]=a>>b;
	c[10]=a&b;
	c[11]=a^b;
	c[12]=a|b;
	c[14]=a<<b;
	float e ;
	e = d;
	d=e;
	
	int* f = &a;
	int a1,a2=0,a3=1,a4=2;
	
	// array typechecking
	int c[4];
	float a6[15][12];
	float a5;
	//int c[12];
	c[2] = a5;
	a6[2][3] = a5;

	a6[2][3] = c[2];

	//pointer testing
	int* single_ptr;
	*single_ptr = c[2];

	*single_ptr = a6[2][5];
	
	c[17] = 3;

	a1=a==b?b:d;		// test ternary operator
	return 0;
}

