int printi(int num);
int prints(char * c);
int readi(int *eP);
int factorial ( int z);		// function declaration
int main()
{
	prints("factorial Program::\n");
	int x,c;
	prints("Input : \n");
	z=readi(&c);
	int m;
	m=factorial(z);
	printi(z);
	prints("! ");
	prints(" is ");
	printi(m);
	prints("\n");
	return 0;
}

// function call
int factorial(int z)
{
	if(z==1)
		return 1;
	else
	{
		return z*factorial(z-1);
	}
}

