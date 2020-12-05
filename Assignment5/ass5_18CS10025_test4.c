

//global variables
int my_atm_pin = 5055;
float my_grade= 9.64, time_now = 03.50;


//function declaration 
int hcf(int n1, int n2);

// function definition 

int addNumbers(int n){
    if(n != 0)
        return n + addNumbers(n-1);
    else
        return n;
}

void main(){
	int n1, n2;		// variable declaration 


	n1 = 10;
	n2 = 75;
	float hcf_n1_n2;
	float a; 
	char test_char;		// type :char
	
	hcf_n1_n2 = hcf(n1, n2);
	
	test_char = 'c';

	int natural_num_sum = addNumbers(hcf_n1_n2);
	//return 0;

}

// function definition 

int hcf(int n1, int n2){
	
    if (n2 != 1)
     return hcf(n2, n1%n2);
    else 
       return n1;
}
