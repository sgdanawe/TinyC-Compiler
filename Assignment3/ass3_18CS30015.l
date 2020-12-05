%{
	#define KEYWORD 101
	#define IDENTIFIER 102
	#define	INTEGER_CONSTANT	103
	#define	FLOATING_POINT_CONSTANT	104
	#define	CHARACTER_CONSTANT	105
	#define	STRINGLITERAl	106
	#define	PUNCTUATOR	107
	#define COMMENT 108
	#define	BREAK	201
	#define	CASE	202
	#define	CHAR	203
	#define	CONTINUE	204
	#define	DEFAULT	205
	#define	DO		206
	#define	DOUBLE	207
	#define	ELSE	208
	#define	EXTERN	109
	#define	FLOAT	110
	#define	FOR		111
	#define	GOTO	112
	#define	IF		113
	#define	INT 	114
	#define	LONG	115
	#define	RETURN	116
	#define	SHORT	117
	#define	SIZEOF	118
	#define	STATIC	119
	#define	STRUCT	120
	#define	SWITCH	121
	#define	TYPEDEF	122
	#define	UNION	123
	#define	VOID	124
	#define	WHILE	125
%}



KEYWORD						"break"|"case"|"char"|"continue"|"default"|"do"|"double"|"else"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"return"|"short"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"void"|"while"
IDENTIFIER					[a-zA-Z]+[0-9]*
INTEGER_CONSTANT			([1-9]+[0-9]*)
FLOATING_POINT_CONSTANT		(([0-9]+)|[0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?
CHARACTER_CONSTANT			(\'([^\"])(\\'|\\\\|\\\?|\\\"|\\a|\\b|\\f|\\n|\\r|\\t|\\v)?\')	
STRINGLITERAl				\"([^\"])*(\\'|\\\\|\\\?|\\\"|\\a|\\b|\\f|\\n|\\r|\\t|\\v)?\"
PUNCTUATOR					\[|\]|\(|\)|\{|\}|\.|->|\+\+|--|&|\*|\+|-|~|!|\/|%|<<|>>|<|>|<=|>=|==|!=|\^|\||&&|"||"|\?|:|;|\.\.\.|=|\*=|\/=|%=|\+=|\-=|<<=|>>=|&=|\^=|\|=|,|#
COMMENT						\/\*([^*]|\*+[^*/])*\*\/|\/\/(.*)
WS							[ \n\t]


%%
{KEYWORD}						{return KEYWORD;}
{IDENTIFIER}					{return IDENTIFIER;}
{INTEGER_CONSTANT}				{return INTEGER_CONSTANT;}
{FLOATING_POINT_CONSTANT}		{return FLOATING_POINT_CONSTANT;}
{CHARACTER_CONSTANT}			{return CHARACTER_CONSTANT;}
{STRINGLITERAl}					{return STRINGLITERAl;}
{PUNCTUATOR}					{return PUNCTUATOR;}
{COMMENT}						;
{WS}							;
%%


int yywrap(void)
{
	return 3;
}
