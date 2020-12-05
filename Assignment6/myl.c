#include "myl.h"
#define MAX_LENGTH 100


int prints(char *inp) 			//prints a stirng of characters and returns the number of characters
{
	int no_of_char=0;
	int i=0;
	while(*(inp+i))
	{
		i++;
		no_of_char++;
	}
	__asm__ __volatile__(
			 "movl $1,%%eax \n\t"
			 "movq $1,%%rdi \n\t"
			 "syscall\n\t"
			 :
			 : "S"(inp) , "d"(no_of_char)
		);
	return no_of_char;
}

int printi(int n)
{
	char num[MAX_LENGTH];
	int i=0;
	if(!n)
	{
		num[i++]='0';
	}
	else if(n<0)
	{
		num[i++]='-';
		n=(-1)*n;
	}
	int l;
	int temp;
	for(l=i;n>0;n=n/10,i++)
	{
		temp=n%10;
		num[i]=(char)(temp+'0');
	}
	int r;
	char temp2;
	r=i-1;
	for(r=i-1;l<=r;l++,r--)
	{
		temp2=num[l];
		num[l]=num[r];
		num[r]=temp2;
	}
	num[i]='\0';
	__asm__ __volatile__(
			"movl $1 ,%%eax \n\t"
			"movq $1 ,%%rdi \n\t"
			"syscall \n\t"
			:
	 		: "S"(num) , "d"(i)
		);
	return i;
}

int readi(int *ep)
{
	const int BUFF_SIZE = 100;
	char buff[BUFF_SIZE];
	int num=0,len=0,i;
	char n[BUFF_SIZE];
	while (1) 
	{
	 __asm__ __volatile__ ("syscall"::"a"(0), "D"(0), "S"(buff), "d"(1));
		if(buff[0]=='\n'||buff[0]=='\t'||buff[0]==' ') 
			break;
		else if (((int)buff[0]-'0'>9||(int)buff[0]-'0'<0)&& buff[0]!='-')
			 *ep=1;
		else
		{
			n[len]=buff[0];
			len++; 
		}
	}
	if(len==0||len>9){
		*ep=1;
		return 0;
	}
	if (n[0]=='-') 
	{
		if(len==1) {
			*ep=1;
			return 0;
		}
		for (i=1;i<len;i++) 
		{
			if(n[i]=='-') 
				*ep=1;
			num=num*10+((int)n[i]-'0');
		}
		num=-num;
	}
	else{
		for (i=0;i<len;i++) 
		{
			if (n[i]=='-') 
				*ep=1;
			num=num*10+((int)n[i]-'0');
		}
	}
	return num;
}


