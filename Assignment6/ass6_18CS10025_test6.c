// include predefined functions 

int prints(char *c);
int printi(int i);
int readi(int *eP);

int maxSubArraySum(int a[], int size) 
{ 
    int max_so_far = -1000, max_ending_here = 0; 
    int i;
    for ( i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} 
  
//Driver program to test maxSubArraySum
int main() 
{ 
    int a[8] ;
    //= {-2, -3, 4, -1, -2, 1, 5, -3}; 
    a[0]= -2;
    a[1]= -3;
    a[2]= 4;
    a[3]= -1;
    a[4]= -2;
    a[5]= 1;
    a[6]= 5;
    a[7]= -3;
    int max_sum = maxSubArraySum(a, 8); 
    prints("Maximum contiguous sum is ");
    printi(max_sum) ;
    return 0; 
}
