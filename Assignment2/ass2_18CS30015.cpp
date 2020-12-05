#define BUFF 100
#define SYS_READ 0
#define STDIN_FILENO 0

int printUpperString(char *str)
{
	char buff[BUFF];
	int i=0,bytes;
	while(*str!='\0')
	{
		if((int)*str>=97 && (int)*str<=122)
			buff[i++]=(char)((int)*str-32);
		else
			buff[i++]=*str;
		++str;
	}
	buff[i]='\n';
	bytes=i;
	__asm__ __volatile__ (
		"movl $1, %%eax \n\t"
		"movq $1, %%rdi \n\t"
		"syscall \n\t"
		:
		:"S" (buff), "d"(bytes)
		);
	return i;
}
int printHexInteger(int n)
{
	char buff[BUFF];
	int i=0,bytes,j,k;
	if(n==0)
		buff[i++]='0';
	else
	{
		if(n<0)
		{
			buff[i++]='-';
			n=-n;
		}
		while(n)
		{
			int temp=n%16;
			if(temp<10)
				buff[i++]=(char)(temp+48);
			else
				buff[i++]=(char)(temp+55);
			n/=16;
		}
		if(buff[0]=='-')
			j=1;
		else
			j=0;
		k=i-1;
		while(j<k)
		{
			char temp=buff[j];
			buff[j++]=buff[k];
			buff[k--]=temp;
		}
	}
	buff[i]='\n';
	bytes=i+1;
	__asm__ __volatile__ (
		"movl $1, %%eax \n\t"
		"movq $1, %%rdi \n\t"
		"syscall \n\t"
		:
		:"S" (buff), "d"(bytes)
		);
	if(i+1<BUFF)
		return i;
	else
		return -1;

}

int printFloat(float f)
{
	char buff[BUFF],zero='0';
	int i=0,bytes,j,k;
	if(f<0)
	{
		buff[i++]='-';
		f=-f;
	}
	int n=(int)f;
	float fp;
	if(n==0)
		fp=f;
	else
		fp=f-n;
	if(n==0) 
		buff[i++]='0';
	else
	{
		while(n)
		{
			int dig=n%10;
			buff[i++]=(char)(zero + dig);
			n/=10;
		}
		if(buff[0]=='-')
			j=1;
		else
			j=0;
		k=i-1;
		while(j<k)
		{
			char temp=buff[j];
			buff[j++]=buff[k];
			buff[k--]=temp;
		}
	}
	buff[i++]='.';
	fp*=10;
	while(fp)
	{
		buff[i++]=(char)(zero + (int)fp);
		fp=fp-(int)fp;
		fp*=10;
	}
	buff[i]='\n';
	bytes=i+1;
	__asm__ __volatile__ (
		"movl $1, %%eax \n\t"
		"movq $1, %%rdi \n\t"
		"syscall \n\t"
		:
		:"S" (buff), "d"(bytes)
		);
	if(i+1<BUFF)
		return i-1;
	else
		return -1;
}

int readFloat(float *f)
{
	(*f)=0;
	char buff[BUFF];
	int length,flag;
	__asm__ __volatile__("syscall"
		:"=a"(length)
		:"0"(SYS_READ),"D"(STDIN_FILENO),"S"(buff),"d"(sizeof(buff))
		:"rcx","r11","memory","cc"
		);
	if(buff[0]=='-')
		flag=1;
	else
		flag=0;
	int pi=0;
	while(buff[pi]!='.')
	{
		if(buff[pi]=='\n')
			break;
		++pi;
	}
	int i,t=1;
	if(flag==1)
		--pi;
	for(i=1;i<pi;++i)
		t*=10;
	i=flag;
	while(t)
	{
		int y;
		if(buff[i]>='0' && buff[i]<='9')
			y=buff[i++]-'0';
		else
			return -1;
		(*f)+=(y*t);
		t/=10;
	}
	t=10;
	if(flag==1)
		++pi;
	i=pi+1;
	if(buff[pi]!='\n')
	{
		if(flag==1)
			(*f)=-(*f);
		return 1;
	}
	else
	{
		while(buff[pi]!='\n')
		{
			int y=buff[i++]-'0';
			(*f)+=(float)((float)y/(float)t);
			t*=10;
		}
		if(flag==1)
			(*f)=-(*f);
		return 1;
	}

	
	
}
int readHexInteger(int *n)
{
	(*n)=0;
	char buff[BUFF];
	int length,flag,i=0;
	__asm__ __volatile__("syscall"
		:"=a"(length)
		:"0"(SYS_READ),"D"(STDIN_FILENO),"S"(buff),"d"(sizeof(buff))
		:"rcx","r11","memory","cc"
		);
	if(buff[0]=='-')
		flag=1;
	else
		flag=0;
	while(buff[i]!='\n')
		++i;
	--i;
	int m=1;
	while(i>=flag)
	{
		int d=0;
		if(buff[i]>='0' && buff[i]<='9')
			d=buff[i] - '0';
		else if(buff[i]>='A' && buff[i]<='F')
			d=buff[i] - 'A' + 10;
		else
			return -1;
		(*n)+=(m*d);
		m*=16;
		--i;
	}
	if(flag==1)
		(*n)=-(*n);
	return 1;
}