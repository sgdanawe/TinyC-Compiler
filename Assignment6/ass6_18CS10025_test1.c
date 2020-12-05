int printi(int num);
int prints(char * c);
int readi(int *eP);
int global_var=0;		// test : global variable
int binarySearch(int a[],int l,int r,int x)
{   global_var++;		// test : incrementor
    int loop_count=0;	
    while(l <= r)		// test : loop
    {	loop_count++;
        int mid=(l+r)/2;
        prints("Mid:");	
        printi(mid);
        prints(" ");
        loop_count++;		
        prints("array[Mid]:");
        printi(a[mid]);
        prints("\n");
        if(a[mid]==x)		// test : conditionals
        {   loop_count++;
        
            return mid;
        }
        else if(a[mid]<x)		// test :  array arithmetic
        {   loop_count++;
            l=mid+1;
        }
        else
        {   loop_count++;
            r=mid-1;
        }
    }
    int b=-1;
    return b;			
}

int main()
{
    int a[10];		// test : array declaration
    int i;
    int c;
    global_var++;
    int loop_count=0;
    for(i=0;i<10;i++)
    {	global_var++; 
        prints("Enter array[");
	printi(i);
	prints("]:\n");
        a[i]=readi(&c);			// test :  read numbers 
        //printi(a[i]);
        prints("\n");
    }
    prints("Entered array :");
    for(i=0;i<10;i++)
    {	global_var++; 
        printi(a[i]);
        prints("\n");
    }
    int x,c,v;
    global_var++;
    prints("Number to search :\n");
    c=readi(&v);
    global_var++;
    x=binarySearch(a,0,9,c);
    global_var++;
    if(x==-1)
        prints("invalid search : not found");
    else { prints("Position:");printi(x);}
    prints("\n");
   return 0;
}

