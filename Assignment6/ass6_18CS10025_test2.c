
//test file to check basic statements, expression, readi and printi library 

//functions created in assignment 2

//also checks the recursive fibonacci function to check the function call and return methodology


int prints(char *c);
int printi(int i);
int readi(int *eP);
int e=5;								// global var testing
int fibonacci(int n)
{
    if(n<=2)
        return 1;
    prints("debug1 \n");
    int d;
    printi(n);
    prints("debug2 \n");
    d=fibonacci(n-1);			// recursive calls
    int c;
    //prints("5 \n");
    c=fibonacci(n-2);
    int e;
    e=d+c;
    //prints("6 \n");
    return e;
}

int main()
{
  int a=5;
  int result;
	result = fibonacci ( a) ; // function invocation
	prints("\nResult = \n");
	printi(result);
  return 0;
}
