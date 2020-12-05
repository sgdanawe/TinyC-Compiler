
// function declaraion 
int Fibonacci(int n);	

// main function
int main(){    
    int n,i;
	float result;
	for( i = 1; i< 4; i++)	{
		n = 2*i;
		result = Fibonacci(n);//n-2 because 2 numbers are already printed   
	}
  return 0;  
 }    

// funciton definition
int Fibonacci(int n){    
    static int n1=0,n2=1,n3;  
	if(n=1)return 1;
	else if ( n=2)return 1;
	return Fibonacci(n-1) + Fibonacci(n-2);
}  
