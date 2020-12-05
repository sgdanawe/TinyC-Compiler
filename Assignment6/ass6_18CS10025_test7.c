//  tests : pointers , array arithemtic printing array elements printing pointers, pointer rithmetic , operations


int prints(char *c);
int printi(int i);
int readi(int *eP);
int e=5;			// test : scope of global variables

int main()
{
  int a=5;
  // test : poiters
  int *d;
  int *e;
  d=&a;
  printi(*d);
	
  e=&a;		// assign same two pointer to a variable
  a++;
  *d=4;
  printi(*d);


   printi(*e);
 // Test Expressions
   int test = 1;
   int a=3, b=2;
  // array operations
   int c[9];
   c[0]=1;
   c[1]=2;
   a=1;
   printi(c[a]); 
   c[0]=*e;
   c[1]=(a+b);
   c[2]=c[0]*c[1];
   c[3]=a*b;
   c[4]=a++;
   c[5]=--b;
   c[6]=0;
   c[7]=a/b;
   c[8]=a%b;
   prints("\nc[0] = \n");printi(c[0]);
   prints("\nc[1] = \n");printi(c[1]);
   prints("\nc[2] = \n");printi(c[2]);
   prints("\nc[3] = \n");printi(c[3]);
   prints("\nc[4] = \n");printi(c[4]);
   prints("\nc[5] = \n");printi(c[5]);
   prints("\nc[6] = \n");printi(c[6]);
   prints("\nc[7] = \n");printi(c[7]);
   prints("\nc[8] = \n");printi(c[8]);

  return 0;
}
