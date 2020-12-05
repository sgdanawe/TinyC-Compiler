// the program tests : function declaration , calling , global variable scope, some operators : / % * ... 
int printi(int num);
int prints(char * c);
int readi(int *eP);
int counter =0;
int pow(int x);		// function declaration
int main()
{	counter++;
	prints("Program calculates power of 2\n");
	prints("Hi!! Enter number:\n");
	int x,c;
	x=readi(&c);
	counter++;
	int ans;
	ans=pow(x);
	prints("2 power ");
	printi(x);
	counter++;
	prints(" is ");
	printi(ans);
	prints("\n");
	prints("counter = ");
	printi(counter);
	return 0;
}
int pow(int x)
{
	if(x==0)
	{	counter--;
		return 1;
	}
	else if(x==1)
	{	counter--;
		return 2;
	}
	else
	{	counter--;
		int m;
		if(x%2==0)
		{	counter--;
			m=pow(x/2);
			return m*m;
		}
		else
		{	counter--;
			m=pow(x/2);
			return m*m*2;
		}
	}
}
