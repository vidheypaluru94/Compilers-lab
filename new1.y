%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "exptree.h"
#include "lex.yy.c"
#include "exptree.c"
#include "symboltable.h"
#include "symboltable.c"
#include "newgen1.c"
int count=1;
int evalutree(struct node *);
int vartype;
struct gsymbol *as;

int *am;
int tem;
%}
%union{
int val;
char *name;
struct node *ptr;
}


%left '+' '-'
%left '*' '/' '%' AND OR NOT
%nonassoc EQUAL
%nonassoc '<'
%nonassoc '>' LE GE NOTE

%token <val>DIGIT
%token <val> FUNCTION
%token <val> NOTE NOT
%token <name> ID
%token <name> ARRAY
%token <val> READ
%token <val> WRITE
%token <val> IF
%token <val> THEN
%token <val> ENDIF
%token <val> WHILE
%token <val> ELSE
%token <val> DO
%token <val> ENDWHILE
%token <val> EQUAL
%token <val> ENDELSE
%token <val> DECL
%token <val> LE GADDRESS LADDRESS
%token <val> GE
%token <val> ENDDECL
%token <val> INTEGER
%token <val> EMPTY
%token <val> BOOL
%token <val> TRUE
%token <val> OR
%token <val> AND
%token <val> FALSE
%token <val> SBEGIN 
%token <name> MAIN
%token <val> END
%token <val> RETURN 
%type <ptr> prog gdefblock fdeflist mainblock gdeflist carglist retstmt

%type <ptr> var arglist argument list fdecl fdecllist
%type <ptr> gdecl fdef farglist fargument flist fidlist
%type <ptr> gidlist
%type <ptr> stlist farglist1 arglist1
%type <ptr>stmt 
%type <ptr> E
%type <ptr> body 
%type <val> ldefblock
%%

prog : gdefblock fdeflist mainblock {int res;//res=evalutree($2);
			//codegen($3);
			//return 1;
			execute();	//added this code so as to get recursive main functions		
			}
	;

gdefblock : DECL gdeflist ENDDECL {}
	;

gdeflist : gdeflist gdecl {}
	| {}
	;

gdecl : type gidlist ';' {
		
		}
		
	;
type: INTEGER {vartype=INTEGER;}
	|BOOL {vartype=BOOL;}

gidlist : gidlist ',' ID {
		ginstall($3,vartype,0,NULL);
		}
	|gidlist ',' ID '[' DIGIT ']' {
		ginstall($3,vartype,$5,NULL);
		}
	| ID {	
		ginstall($1,vartype,0,NULL);
		}
	| ID '[' DIGIT ']' {
		ginstall($1,vartype,$3,NULL);
		}
	| ID '(' arglist ')' {
		flag=1;		
		ginstall($1,vartype,0,argulist);
		argulist=NULL;//doubt		
		}	
	;

argument : type list  {
		
		}	
	;




arglist : arglist1 argument {}
	| {}
arglist1 : arglist1 argument ';'  {}
	|  {}
	;

list : ID {	
		addargument(vartype,$1);	
		}
		
	    | list ',' ID {
		addargument(vartype,$3);		

		}
	    |'&' ID {
		addargument(vartype,$2);
		}
	    |list ',' '&' ID {
		addargument(vartype,$4);		
		}
	;






fdeflist : fdeflist fdef {} 
	| {}
	;

fdef : type ID '(' farglist ')' '{' ldefblock body '}' {
					$$=makenode(vartype,FUNCTION,0,$2,$8,NULL,NULL,NULL);typecheck($$);
					fungen($$);
					}
	;

body : SBEGIN stlist retstmt END {$$=makenode(0,FUNCTION,0,NULL,$2,NULL,$3,NULL);}
	;


farglist : farglist1 fargument {}
	| {}	 
	; 

farglist1 : farglist1 fargument';' {}
	| {}
	;

fargument : type flist {
			}
	;
flist : '&' ID{
		if(flag1==0){
		flag1=1;	
		linstall($2,vartype);	
		lsymbol->reftype=1;
		}		
}
	| flist ',' '&' ID {
	if(flag1==0){
		flag1=1;	
		linstall($4,vartype);	
		lsymbol->reftype=1;
		}		
}	
	|ID {
		if(flag1==0){
		flag1=1;	
		linstall($1,vartype);	
		lsymbol->reftype=0;
		}		
		}
		
	 | flist ',' ID {
		if(flag1==0){
		flag1=1;	
		linstall($3,vartype);
		lsymbol->reftype=0;		
		}		
		
		}
	 ;

ldefblock : DECL fdecllist ENDDECL
	;
fdecllist :fdecllist fdecl {} 
	 | {}
	;
fdecl : type fidlist ';' {
		}
	;

fidlist : fidlist ',' ID {
		linstall($3,vartype);
		lsymbol->reftype=0;
		}
	| ID {	
		linstall($1,vartype);
		lsymbol->reftype=0;
		}	
	;

















mainblock : INTEGER MAIN '(' ')' '{' ldefblock body '}' {
							$$=makenode(INTEGER,FUNCTION,0,$2,$7,NULL,NULL,NULL);typecheck($$);
							fungen($$);
							}
		






stlist : stlist stmt 							{$$=makenode(0,EMPTY,0,NULL,$1,NULL,$2,NULL);}
	| {$$=NULL;}	
	
	;


var : ID								{struct lsymbol *z=llookup($1);
									if(z==NULL){
									struct gsymbol *p=glookup($1);
									$$=makenode(p->type,ID,0,$1,NULL,NULL,NULL,p);									
									$$->lentry=NULL;									
									}
									else{
									$$=makenode(z->type,ID,0,$1,NULL,NULL,NULL,NULL);  										$$->lentry=z;
									
									}
									typecheck($$);	}
	|ID '[' E ']'							{struct gsymbol *p=glookup($1);$$=makenode(p->type,ARRAY,0,$1,$3,NULL,NULL,p);typecheck($$);	}


stmt : var '=' E ';' 							{$$=makenode(0,'=',0,NULL,$1,NULL,$3,NULL);typecheck($$);}
		
	| READ '(' var ')' ';' 						{$$=makenode(0,READ,0,NULL,$3,NULL,NULL,NULL);typecheck($$);}
	| WRITE '(' E ')' ';' 						{$$=makenode(0,WRITE,0,NULL,$3,NULL,NULL,NULL);typecheck($$);}	
	| IF '(' E ')' THEN stlist ENDIF ';' 				{$$=makenode(0,IF,0,NULL,$3,NULL,$6,NULL);typecheck($$);}
	| WHILE '(' E ')' DO stlist ENDWHILE ';' 			{$$=makenode(0,WHILE,0,NULL,$3,NULL,$6,NULL);typecheck($$);}
	| IF '(' E ')' THEN stlist ELSE stlist ENDELSE ';' 		{$$=makenode(0,IF,0,NULL,$3,$6,$8,NULL);typecheck($$);}

	;  

E :  	var								{$$=$1;}
	|ID '(' carglist ')' 						{struct gsymbol *p;p=glookup($1);
									$$=makenode(p->type,FUNCTION,0,$1,NULL,NULL,NULL,NULL);typecheck($$);$$->arg=$3;}
	
	|DIGIT 								{$$=makenode(INTEGER,DIGIT,$1,NULL,NULL,NULL,NULL,NULL);}
	|TRUE								{$$=makenode(BOOL,TRUE,1,NULL,NULL,NULL,NULL,NULL);}
	|FALSE								{$$=makenode(BOOL,FALSE,0,NULL,NULL,NULL,NULL,NULL);}
	|'(' E ')' 							{$$=$2;}
	| E '>' E  							{$$=makenode(BOOL,'>',0,NULL,$1,NULL,$3,NULL);typecheck($$);}
	| E '<' E 							{$$=makenode(BOOL,'<',0,NULL,$1,NULL,$3,NULL);typecheck($$);}	
	|E '+' E 							{$$=makenode(INTEGER,'+',0,NULL,$1,NULL,$3,NULL);typecheck($$);}
	|E '*' E 							{$$=makenode(INTEGER,'*',0,NULL,$1,NULL,$3,NULL);typecheck($$);}
	|E '-' E							{$$=makenode(INTEGER,'-',0,NULL,$1,NULL,$3,NULL);typecheck($$);}
	|E '/' E							{$$=makenode(INTEGER,'*',0,NULL,$1,NULL,$3,NULL);typecheck($$);}
	|E LE E								{$$=makenode(BOOL,LE,0,NULL,$1,NULL,$3,NULL);typecheck($$);}
	|E GE E								{$$=makenode(BOOL,GE,0,NULL,$1,NULL,$3,NULL);typecheck($$);}
	|E EQUAL E 							{$$=makenode(BOOL,EQUAL,0,NULL,$1,NULL,$3,NULL);typecheck($$);}
	|E '%' E 							{$$=makenode(INTEGER,'%',0,NULL,$1,NULL,$3,NULL);typecheck($$);}
	|E NOTE E							{$$=makenode(BOOL,NOTE,0,NULL,$1,NULL,$3,NULL);typecheck($$);}
	|E AND E							{$$=makenode(BOOL,AND,0,NULL,$1,NULL,$3,NULL);typecheck($$);}
	|E OR E 							{$$=makenode(BOOL,OR,0,NULL,$1,NULL,$3,NULL);typecheck($$);}
	|NOT E								{$$=makenode(BOOL,NOT,0,NULL,$2,NULL,NULL,NULL);typecheck($$);}


retstmt : RETURN E ';'							{$$=$2;}



carglist : 
	carglist ',' E {$$=makenode(0,EMPTY,0,NULL,$1,NULL,$3,NULL);}
	| E {$$=$1;}
	| carglist ',' '&' ID {struct node *t;
				struct lsymbol *d;d=llookup($4);
		if(d==NULL){
		struct gsymbol *z;z=glookup($4);
		t=makenode(0,GADDRESS,z->binding,NULL,NULL,NULL,NULL,NULL);	
	}else{
		t=makenode(0,LADDRESS,d->binding,NULL,NULL,NULL,NULL,NULL);		
	}	
	$$=makenode(0,EMPTY,0,NULL,$1,NULL,t,NULL);
		}
	| '&' ID {
				struct lsymbol *d;d=llookup($2);

		if(d==NULL){
		struct gsymbol *z;z=glookup($2);		
		$$=makenode(0,GADDRESS,z->binding,NULL,NULL,NULL,NULL,NULL);	
	}else{
		$$=makenode(0,LADDRESS,d->binding,NULL,NULL,NULL,NULL,NULL);		
	}	
			
		} 
	| carglist ',' '&' ID '[' E ']' {struct gsymbol *z;z=glookup($4);
		struct node *t;
		t=makenode(0,GADDRESS,z->binding,NULL,$6,NULL,NULL,NULL);	
		$$=makenode(0,EMPTY,0,NULL,$1,NULL,t,NULL);		
		}	
	| '&' ID '[' E ']' {struct gsymbol *z;z=glookup($2);
	$$=makenode(0,GADDRESS,z->binding,NULL,$4,NULL,NULL,NULL);	
	}
	| {$$=NULL;}	
	;





%%
yyerror(){
printf("error%d",count);
exit(1);
}

int typecheck(struct node *nd){


if(nd->nodetype==FUNCTION){
struct gsymbol *t;
if(strcmp(nd->id,"main")!=0){
t=glookup(nd->id);

if(t==NULL){
printf("no such function is declared");
yyerror();
}
}
}


if(nd->nodetype==ID){
if(nd->gentry!=NULL){
if(nd->gentry->size>0){
printf("given identifier is an array");
yyerror();
}
}
}

if(nd->nodetype==ARRAY){

if(nd->gentry->size==0){
printf("given identifier is an integer");
yyerror();
}


if(nd->left->type!=INTEGER){
printf("expression should not boolean in array\n");
yyerror();

}
}





if(nd->nodetype==READ){
if(nd->left->type!=INTEGER){
printf("only integers can be read\n");
yyerror();
}


}

if(nd->nodetype==WRITE){
if(nd->left->type!=INTEGER){
printf("only integers can be written\n");
yyerror();

}
}

if(nd->nodetype=='=')
{
if(nd->left->type==INTEGER){
if(!(nd->right->type==INTEGER)){
printf("error conflicting nodetypes not integer%d",count);
yyerror();
}
}
if(nd->left->type==BOOL){
if(!(nd->right->type==BOOL)){
printf("error conflicting nodetypes not bool%d",count);
yyerror();
}
}


}

if(nd->nodetype==NOT){
if(nd->left->type!=BOOL){
printf("error conflicting nodetypes%d",count);
yyerror();
return 0;

}
}


if((nd->nodetype==AND)||(nd->nodetype==OR)){
if(!((nd->left->type==BOOL)&&(nd->right->type==BOOL)))
{

printf("error conflicting nodetypes%d",count);
yyerror();
return 0;
}

}





return 0;

int a[] = {'>' ,'<','+','-','*','/' , LE, GE,NOTE,EQUAL};
int i;
for(i=0;i<9;i++){
if(nd->nodetype==a[i]){
if(!((nd->left->type==INTEGER)&&(nd->right->type==INTEGER))){

printf("error conflicting nodetypes not integer%d",count);
yyerror();
return 0;
}

}


}
}


/*
int evalutree(struct node *nd){

if(nd==NULL){
return 1;
}



if(nd->nodetype==TRUE){
return 1;
}

if(nd->nodetype==FALSE){
return 0;
}


if(nd->nodetype==EMPTY){
int dum;
evalutree(nd->left);
evalutree(nd->right);
return 1;
}

if(nd->nodetype== EQUAL){
if(evalutree(nd->left)==evalutree(nd->right)){
return 1;
}
return 0;

}

if(nd->nodetype==LE){
if(evalutree(nd->left)<=evalutree(nd->right)){
return 1;
}
return 0;
}
if(nd->nodetype==NOTE){
if(evalutree(nd->left)!=evalutree(nd->right)){
return 1;
}
return 0;
}


if(nd->nodetype==AND){
if(evalutree(nd->left)&&evalutree(nd->right)){
return 1;
}
return 0;
}

if(nd->nodetype==NOT){
return (!evalutree(nd->left));
}

if(nd->nodetype==OR){
if(evalutree(nd->left)||evalutree(nd->right)){
return 1;
}
return 0;
}




if(nd->nodetype==GE){
if(evalutree(nd->left)>=evalutree(nd->right)){
return 1;
}
return 0;
}

if(nd->nodetype=='='){

as=glookup(nd->left->id);
if(nd->left->nodetype==ID){
as->binding[nd->left->val]=evalutree(nd->right);
}
if(nd->left->nodetype==ARRAY){
as->binding[evalutree(nd->left->left)]=evalutree(nd->right);

}
return 1;
}

if(nd->nodetype=='+'){
return evalutree(nd->left)+evalutree(nd->right);
}

if(nd->nodetype=='%'){
return evalutree(nd->left)%evalutree(nd->right);

}

if(nd->nodetype=='*'){
return evalutree(nd->left)*evalutree(nd->right);
}

if(nd->nodetype=='-'){
return evalutree(nd->left)-evalutree(nd->right);
}

if(nd->nodetype=='/'){
return evalutree(nd->left)/evalutree(nd->right);
}


if(nd->nodetype=='<'){
if(evalutree(nd->left) < evalutree(nd->right)){
return 1;

}
return 0;
}


if(nd->nodetype=='>'){
if(evalutree(nd->left)>evalutree(nd->right)){
return 1;
}
return 0;
}

if(nd->nodetype==DIGIT){
return nd->val;
}


if((nd->type==BOOL)||(nd->type==INTEGER)){

as=glookup(nd->id);


if(nd->left==NULL){
return as->binding[0];

}
return as->binding[evalutree(nd->left)];
}



if(nd->nodetype==WRITE){

printf("%d\n",evalutree(nd->left));
return 1;

}

if(nd->nodetype==READ){

scanf("%d",&tem);

as=glookup(nd->left->id);
if(nd->left->nodetype==ID){

as->binding[0]=tem;
}
if(nd->left->nodetype==ARRAY){
as->binding[evalutree(nd->left->left)]=tem;
}
return 1;
}




if(nd->nodetype==WHILE){
while(evalutree(nd->left)){
evalutree(nd->right);

}
return 1;


}
if(nd->nodetype==IF){
if(evalutree(nd->left)){
evalutree(nd->right);
return 1;
}
else{
if(nd->middle!=NULL){
evalutree(nd->middle);

}

return 0;

}
}

}

*/	

int main(int argc,char *argv[]){

fp=fopen("sim-2/openfile","w");


yyin=fopen(argv[1],"r");




yyparse();



return 0;
}
