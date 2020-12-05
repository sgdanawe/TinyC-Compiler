#include<stdio.h>
extern int yylex();
extern int yylineno;
extern  char* yytext;
#define KEYWORD 101
#define IDENTIFIER 102
#define	INTEGER_CONSTANT	103
#define	FLOATING_POINT_CONSTANT	104
#define	CHARACTER_CONSTANT	105
#define	STRINGLITERAl	106
#define	PUNCTUATOR	107
#define COMMENT 108

int main()
{
	extern FILE *yyin;
	yyin=fopen("ass3_18CS30015_test.c","r");
	int token;
	while(token=yylex()){
		switch(token){
			case KEYWORD:printf("<KEYWORD, %d, %s>\n",token,yytext); break;
			case IDENTIFIER:printf("<IDENTIFIER,%d, %s>\n",token,yytext); break;
			case INTEGER_CONSTANT:printf("<CONSTANT, %d, %s>\n",token,yytext); break;
			case FLOATING_POINT_CONSTANT:printf("<CONSTANT, %d, %s>\n",token,yytext); break;
			case CHARACTER_CONSTANT:printf("<CONSTANT, %d, %s>\n",token,yytext); break;
			case STRINGLITERAl:printf("<STRINGLITERAl, %d, %s>\n",token,yytext); break;
			case PUNCTUATOR:printf("<PUNCTUATOR, %d, %s>\n",token,yytext); break;
			
		}
	}
	return 0;
}

#include<stdio.h>
#include<string.h>
int main()
{
	int 1x32;
	//int -y0;
	char ddd[]="\niuhokjijohin";
	float
	char gfhjhk='a';
	/*jgsghudgfkjdnvmldnvlnj

	iygfjdkjbkjfdnv
	kfbfkjvnjon*/
	if(x>5)
	{
		if(y>=7/*|=\\*/)
			continue;
	}
	x=-2.354e-10;
	y=000;
	x=5+y*4;
	>>=;
	>;
	return 0;
}
