%{
	#include"y.tab.h"
	extern int line_count;
%}

digit	   [0-9]
identifier [A-Za-z][A-Za-z0-9]*
op	   ["+"|\-|"*"|"/"|"%"|"("|")"|"="|";"|"{"|"}"|","|\[|\]|\&]
equals 		==

%%

main 		{return MAIN;}

begin		{return BEG;}
return 		{return RETURN;}
end 		{return END;}

{digit}+	{yylval.val=atoi(yytext); return NUM;}

write		{return WRITE;}
read		{return READ;}

if			{return IF;}
then		{return THEN;}
else		{return ELSE;}
endif		{return ENDIF;}

while		{return WHILE;}
do			{return DO;}
endwhile	{return ENDWHILE;}

decl		{return DECL;}
enddecl		{return ENDDECL;}

integer		{return INTEGER;}
boolean		{return BOOLEAN;}

true		{return TRUE;}
false		{return FALSE;}

and 		{return AND;}
or			{return OR;}
not			{return NOT;}

{identifier}	{unsigned int a=yyleng;
				 yylval.identifier=malloc((a+1)*sizeof(char));
				 strcpy(yylval.identifier,yytext);
				 return ID;}

"=="		{return EQ;}
"<"			{return LT;}
"<="		{return LE;}
">"			{return GT;}
">="		{return GE;}
"!="		{return NE;}

{op}		{return *yytext;}

[ \t]		;
["\n"]		{line_count++;}

%%

int yywrap()
{
	return 1;
}
