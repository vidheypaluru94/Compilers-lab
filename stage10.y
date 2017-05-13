%{
	#include<stdio.h>
	#include<stdlib.h>
	#include "lex.yy.c"
	#include "sym_table.h"
	#include "exprtree.h"

	#define ID_ARRAY 1003
	int evaluate(struct tree_node *);
	void typecheck(struct tree_node *root,struct tree_node *,struct tree_node *,struct tree_node *);
	int vartype;
	int argtype;
	extern struct Argstruct *Arg_List;
	int line_count = 0;
	extern int sp;
	extern int Arg_bind;
	int getbind(char *name);

	int free_reg=-1;
	extern int start_addr;
	int evaluate(struct tree_node *);
	void freereg(int);
	int getreg();
	int codegen(struct tree_node *,FILE *);
	void Argcheck(int type, char *name, struct Argstruct *Arglist);
	FILE *outfile;
%}

%union {
	int val;
	char* identifier;
	struct tree_node *ptr;
}

%token <val> VARLIST
%token <val> FUNCT

%token <val> VALUE
%token <val> REFERENCE
%token <val> ID_REF
%token <val> ID_ARRAY_REF

%token <val> MAIN
%token <val> BODY

%token <val> BEG
%token <val> RETURN
%token <val> END

%token <val>  NUM
%token <identifier> ID

%token <val> WRITE
%token <val> READ

%token <val> IF
%token <val> THEN
%token <val> ELSE
%token <val> ENDIF

%token <val> WHILE
%token <val> DO
%token <val> ENDWHILE

%token <val> BOOLEAN
%token <val> INTEGER
%token <val> VOID

%token <val> DECL
%token <val> ENDDECL

%token <val> TRUE
%token <val> FALSE

%token <val> AND
%token <val> OR
%token <val> NOT

%token <val> LT
%token <val> LE
%token <val> GT
%token <val> GE
%token <val> EQ
%token <val> NE

%type <val> Type
%type <ptr> Stmt
%type <ptr> E
%type <ptr> StmtList
%type <ptr> var
%type <ptr> Body
%type <ptr> RetStmt
%type <ptr> AsgStmt
%type <ptr> CondStmt
%type <ptr> IterStmt
%type <ptr> InOutStmt
%type <ptr> varlist

%left '%' ','
%left '+' '-' 
%left '*' '/' AND OR NOT
%nonassoc LT LE GT GE EQ NE

%%

prog : GDefblock FdefList Mainblock		
	;
//---------------------------------------------------------------------------------------------------------------------------------

GDefblock : DECL GDeflist ENDDECL 
	;

GDeflist : GDeflist Gdecl				// done //
	  	 |				
	;

Gdecl : Type GIDlist ';'		
	;

Type : INTEGER					{vartype = INTEGER;$$=INTEGER;}
	 | BOOLEAN					{vartype = BOOLEAN;$$=BOOLEAN;}
	;

GIDlist : GIDlist ',' GId
		| GId
	;

GId	: ID 					{Ginstall($1,vartype,1,ID,NULL);}
	| ID '[' NUM ']'		{Ginstall($1,vartype,$3,ID_ARRAY,NULL);}
	| ID '(' ArgDeflist ')'	{Ginstall($1,vartype,0,FUNCT,Arg_List); Arg_List = NULL; Arg_bind = 0;}
	;

ArgDeflist : ArgDeflist ';' Argdecl
		   | Argdecl
		   |
	;

Argdecl : ArgType ArgList
	;

ArgType : INTEGER				{argtype = INTEGER;}
		| BOOLEAN				{argtype = BOOLEAN;}
	;

ArgList : ArgList ',' ArgId
		| ArgId
	;

ArgId : ID 					{ Arginstall(argtype,VALUE,$1); }
	  | '&' ID				{ Arginstall(argtype,REFERENCE,$2); }
	 ;

//-------------------------------------------------------------------------------------------------------------------------------------

FdefList : FdefList Fdef
		 |
	;

Fdef : Type ID '(' ArgDeflist ')' '{' LDefblock Body '}' {	int r,r1;
														Argcheck($1,$2,Arg_List);
														free_reg = -1;
														fprintf(outfile,"\n%s: \n", $2);
														fprintf(outfile,"PUSH BP\n");
														fprintf(outfile,"MOV BP, SP\n");

														r = getreg();
														r1 = getreg();
														fprintf(outfile,"MOV R%d, %d\n",r,sp);
														fprintf(outfile,"MOV R%d, SP\n",r1);
														fprintf(outfile,"ADD R%d, R%d\n",r,r1);
														fprintf(outfile,"MOV SP, R%d\n",r);
														freereg(r);
														freereg(r1);

														struct tree_node *node = $8;

														if($8->r->type != $1) {
															printf("return type mismatch");
															yyerror();
														}

														codegen($8->l,outfile);
														r1 = codegen($8->r,outfile);
														r = getreg();
														fprintf(outfile,"MOV R%d, BP\n",r);
														fprintf(outfile,"DCR R%d\n",r);
														fprintf(outfile,"DCR R%d\n",r);
														fprintf(outfile,"MOV [R%d], R%d\n",r,r1);
														freereg(r1);
														freereg(r);

														r = getreg();
														fprintf(outfile,"MOV SP, BP\n");
														fprintf(outfile,"POP R%d\n",r);
														fprintf(outfile,"MOV BP, R%d\n",r);
														freereg(r);

														fprintf(outfile,"RET\n\n");

														Arg_List = NULL;		// actually delete operation is to be done //
														Lsymbol_Table = NULL;	// actually delete operation is to be done //
														sp=0;
														Arg_bind = 0;
													  }
	;

LDefblock : DECL LDeflist ENDDECL

LDeflist : LDeflist Ldecl						// done //
		  |
	;

Ldecl : Type LIDlist ';'
	;

LIDlist : LIDlist ',' LId
		| LId
	;

LId : ID 												{Linstall($1,vartype);}
	;
//--------------------------------------------------------------------------------------------------------------------------------------
Mainblock : INTEGER MAIN '(' ')' '{' LDefblock Body '}' {	int t,r1,r;
															fprintf(outfile,"\nSTART\n");
															fprintf(outfile,"MOV BP, 0\n");
															fprintf(outfile,"MOV SP, %d\n",start_addr-1);
															fprintf(outfile,"PUSH BP\n");
															fprintf(outfile,"MOV BP, SP\n");
															free_reg = -1;
															
															r = getreg();
															r1 = getreg();
															fprintf(outfile,"MOV R%d, %d\n",r,sp);
															fprintf(outfile,"MOV R%d, SP\n",r1);
															fprintf(outfile,"ADD R%d, R%d\n",r,r1);
															fprintf(outfile,"MOV SP, R%d\n",r);
															freereg(r);
															freereg(r1);
				// done //											
															codegen($7->l,outfile);

															fprintf(outfile,"HALT");
															printf("complete %d",free_reg);
															fclose(outfile);}
	;
//---------------------------------------------------------------------------------------------------------------------------------------

Body : BEG StmtList RetStmt END 		{$$ = makenode(VOID,BODY,NULL,-1,$2,NULL,$3);}
	;

StmtList: StmtList Stmt 				{$$=makenode(VOID,3,NULL,-1,$1,NULL,$2);}
	 	| Stmt							{$$=$1;}
	;

Stmt : AsgStmt							{$$ = $1;}
	 | CondStmt							{$$ = $1;}
	 | IterStmt							{$$ = $1;}
	 | InOutStmt						{$$ = $1;}
	 ;

AsgStmt :	var '=' E ';'				{$$ = makenode(VOID, '=', NULL, -1, $1,NULL,$3);			typecheck($$,$$->l,$$->m,$$->r);}
	;

InOutStmt : READ '(' var ')' ';'		{$$ = makenode(VOID, READ, NULL, -1, $3,NULL,NULL);			typecheck($$,$$->l,$$->m,$$->r);}
     	  | WRITE '(' E ')' ';'			{$$ = makenode(VOID, WRITE,NULL, -1, $3,NULL,NULL);			typecheck($$,$$->l,$$->m,$$->r);}
    ;

CondStmt : IF '(' E ')' THEN StmtList ENDIF ';'	{$$ = makenode(VOID, IF,NULL, -1, $3,$6,NULL);		typecheck($$,$$->l,$$->m,$$->r);}
		 | IF '(' E ')' THEN StmtList ELSE StmtList ENDIF ';'	{$$ = makenode(VOID, ELSE,NULL,-1,$3,$6,$8);}
	;

IterStmt : WHILE '(' E ')' DO StmtList ENDWHILE ';'	{$$ = makenode(VOID, WHILE,NULL,-1,$3,$6,NULL);	typecheck($$,$$->l,$$->m,$$->r);}
	;

RetStmt : RETURN E ';'				{$$ = $2;}

E    : E '+' E					{$$ = makenode(INTEGER, '+', NULL, -1, $1, NULL, $3);typecheck($$,$$->l,$$->m,$$->r);}
	 | E '-' E 					{$$ = makenode(INTEGER, '-', NULL, -1, $1, NULL, $3);typecheck($$,$$->l,$$->m,$$->r);}
     | E '*' E					{$$ = makenode(INTEGER, '*', NULL, -1, $1, NULL, $3);typecheck($$,$$->l,$$->m,$$->r);}
     | E '/' E 					{$$ = makenode(INTEGER, '/', NULL, -1, $1, NULL, $3);typecheck($$,$$->l,$$->m,$$->r);}
     | E '%' E 					{$$ = makenode(INTEGER, '%', NULL, -1, $1, NULL, $3);typecheck($$,$$->l,$$->m,$$->r);}

     | '(' E ')'				{$$ = $2;}

     | ID '(' varlist ')'		{$$ = makenode(INTEGER,FUNCT, $1, -1, $3, NULL, NULL);typecheck($$,$$->l,$$->m,$$->r);}
     																									// typecheck to be performed //
     | E LT E 					{$$ = makenode(BOOLEAN, LT, NULL, -1, $1, NULL, $3);typecheck($$,$$->l,$$->m,$$->r);}
     | E LE E 					{$$ = makenode(BOOLEAN, LE, NULL, -1, $1, NULL, $3);typecheck($$,$$->l,$$->m,$$->r);}
     | E GT E					{$$ = makenode(BOOLEAN, GT, NULL, -1, $1, NULL, $3);typecheck($$,$$->l,$$->m,$$->r);}
     | E GE E 					{$$ = makenode(BOOLEAN, GE, NULL, -1, $1, NULL, $3);typecheck($$,$$->l,$$->m,$$->r);}
     | E EQ E					{$$ = makenode(BOOLEAN, EQ, NULL, -1, $1, NULL, $3);typecheck($$,$$->l,$$->m,$$->r);}
     | E NE E 					{$$ = makenode(BOOLEAN, NE, NULL, -1, $1, NULL, $3);typecheck($$,$$->l,$$->m,$$->r);}

     | E AND E 					{$$ = makenode(BOOLEAN, AND, NULL, -1, $1, NULL, $3);typecheck($$,$$->l,$$->m,$$->r);}
     | E OR E 					{$$ = makenode(BOOLEAN, OR, NULL, -1, $1, NULL, $3);typecheck($$,$$->l,$$->m,$$->r);}
     | NOT E 					{$$ = makenode(BOOLEAN, NOT, NULL, -1, $2, NULL, NULL);typecheck($$,$$->l,$$->m,$$->r);}
     
     | TRUE						{$$ = makenode(BOOLEAN, TRUE, NULL, -1, NULL, NULL, NULL);}
     | FALSE					{$$ = makenode(BOOLEAN, FALSE, NULL, -1, NULL, NULL, NULL);}
     
     | NUM					{$$ = makenode(INTEGER, NUM, NULL, $1, NULL, NULL, NULL);}
     | var 					{$$ = $1;}
     ;

varlist : varlist ',' E 		{$$ = makenode(VOID, VARLIST, NULL, -1, $1, NULL, $3);}

		| varlist ',' '&' var 	{	if($4->nodetype == ID)
										$4->nodetype = ID_REF;
									else if($4->nodetype == ID_ARRAY)
										$4->nodetype = ID_ARRAY_REF;
									$$ = makenode(VOID, VARLIST, NULL, -1, $1, NULL, $4);}

		| E 					{$$ = makenode(VOID, VARLIST, NULL, -1, NULL, NULL, $1);}

		| '&' var  				{	if($2->nodetype == ID)
										$2->nodetype = ID_REF;
									else if($2->nodetype == ID_ARRAY)
										$2->nodetype = ID_ARRAY_REF;
									$$ = makenode(VOID, VARLIST, NULL, -1, NULL, NULL, $2);
								}

		|						{$$ = makenode(VOID, VARLIST, NULL, -1, NULL, NULL, NULL);}
	;

var : ID					{$$ = makenode(INTEGER, ID, $1, -1, NULL,NULL,NULL);typecheck($$,$$->l,$$->m,$$->r);}
	| ID '[' E ']'		{$$ = makenode(INTEGER, ID_ARRAY,$1,-1,$3,NULL,NULL);
/*							struct Gsymbol *temp;
							temp = Glookup($1);
							if(temp->size == -1)
							{
								printf("error ");
								yyerror();
							}*/
						typecheck($$,$$->l,$$->m,$$->r);}
	;
//--------------------------------------------------------------------------------------------------------------------------------------
%%

void Argcheck(int type, char *name, struct Argstruct *Arglist){
	struct Gsymbol *temp = Glookup(name);
	struct Argstruct *temp1 = temp->arglist;
	if(temp->binding == 0)
		temp->binding = 1;
	else
	{
		printf("error - two definition of same function %s\n",name);
		yyerror();
	}
	if(temp->type == type){
		while(temp1 != NULL) {
			if((strcmp(temp1->name,Arglist->name) == 0) && temp1->type == Arglist->type && temp1->passby == Arglist->passby)
				;
			else {
				printf("error in arglist of function %s",name);
				yyerror();
			}
			temp1 = temp1->next;
			Arglist = Arglist->next;
		}
		if(temp1 != NULL || Arglist != NULL) {
			printf("error arguments mismatch in %s", name);
			yyerror();
		}
	}
	else {
		printf("error in type of the function\n");
		yyerror();
	}
}

void typecheck(struct tree_node *root,struct tree_node *l,struct tree_node *m,struct tree_node *r)
{
	struct Gsymbol *temp = NULL;
	struct Argstruct *temp1 = NULL;

	if(root->nodetype == FUNCT) {
		temp = Glookup(root->name);
		temp1 = temp->arglist;
		if(temp != NULL) {
			while(l != NULL && l->r != NULL && temp1 != NULL) {
				if(temp1->type != l->r->type) {
					printf("error in types of function");
					yyerror();
				}
				temp1=temp1->next;
				l = l->l;
			}
			if(temp1 != NULL || l != NULL){
				printf("error in no of args in funct in typecheck");
				yyerror();
			}
		}
		else {
			printf("error in typecheck of funct");
			yyerror();
		}
	}

	else if(root->nodetype == ID) {
		struct Gsymbol *temp = root->Gentry;
		struct Lsymbol *temp1 = root->Lentry;
		struct Argstruct *temp2 = Arglookup(root->name);
		if(temp==NULL && temp1 == NULL && temp2 == NULL) {
			printf("error - identifier not declared");
			yyerror();
		}
		if(temp1==NULL && temp2==NULL && temp!=NULL && temp->nodetype != ID) {
			 printf("error - variable declared as array");
			 yyerror();
		}
	}

	else if(root->nodetype == ID_ARRAY)
	{
		struct Gsymbol *temp = root->Gentry;
		struct Lsymbol *temp1 = root->Lentry;
		struct Argstruct *temp2 = Arglookup(root->name);
		if(temp == NULL) {
			printf("error array declaration not found");
			yyerror();
		}
		if(root->l->type != INTEGER) {
			printf("error expr in array is not integer");
		}
	}

	else if(root->nodetype == '+' || root->nodetype == '-' || root->nodetype == '*' || root->nodetype == '/' || root->nodetype == '%')
	{
		if(l->type == INTEGER && r->type == INTEGER)
			;
		else
		{
		printf("error in operator");
		yyerror();
		}
	}
	else if(root->nodetype == LT || root->nodetype == LE || root->nodetype == GT || root->nodetype == GE || root->nodetype == EQ || root->nodetype == NE )
	{
		if(l->type == INTEGER && r->type == INTEGER)
			;
		else
		{
		printf("error in relop");
		yyerror();
		}
	}
	else if(root->nodetype == AND || root->nodetype == OR)
	{
		if(l->type == BOOLEAN && r->type == BOOLEAN)
			;
		else
		{
		printf("error in AND | OR");
		yyerror();
		}
	}
	else if(root->nodetype == NOT)
	{
		if(l->type == BOOLEAN)
			;
		else
		{
		printf("error in NOT");
		yyerror();
		}
	}
	else if(root->nodetype == IF)
	{
		if(l->type == BOOLEAN && m->type == VOID)
			;
		else
		{
		printf("error in IF");
		yyerror();
		}
	}
	else if(root->nodetype == WHILE)
	{
		if(l->type == BOOLEAN && m->type == VOID)
			;
		else
		{
		printf("error in WHILE");
		yyerror();
		}

	}
	else if(root->nodetype == READ)
	{
		if(l->type == INTEGER)
			;
		else
		{
		printf("error in READ ");
		yyerror();
		}
	}
	else if(root->nodetype == WRITE)
	{
		if(l->type == INTEGER)
			;
		else
		{
		printf("error in WRITE ");
		yyerror();
		}
	}
	else if(root->nodetype == '=')
	{
		if(l->type == INTEGER && r->type == INTEGER)
			;
		else if(l->type == BOOLEAN && r->type == BOOLEAN)
			;
		else
		{
		printf("error in = ");
		yyerror();
		}
	}
}

int getreg(){
	free_reg++;
	return free_reg;
}

void freereg(int r){
		free_reg--;
}

int getlabel()
{
	static int l=0;
	return ++l;
}

int getbind(char *name){
	int r1,r2,loc,r3;
	r1=getreg();
	r2=getreg();
	struct Gsymbol *temp1 = NULL;
	struct Lsymbol *temp2 = NULL;
	struct Argstruct *temp3 = NULL;
	temp3 = Arglookup(name);
	temp2 = Llookup(name);
	temp1 = Glookup(name);
	if(temp3 != NULL) {
		loc = temp3->argbind + 2;
		fprintf(outfile,"MOV R%d, BP\n",r1);
		fprintf(outfile,"MOV R%d, %d\n",r2,loc);
		fprintf(outfile,"SUB R%d, R%d\n",r1,r2);
		if(temp3->passby == REFERENCE) {
			fprintf(outfile,"MOV R%d, [R%d]\n",r2,r1);
			fprintf(outfile,"MOV R%d, R%d\n",r1,r2);
//			fprintf(outfile,"MOV R%d, [BP]\n",r1);
//			fprintf(outfile,"ADD R%d, R%d\n",r1,r2);
		}
		freereg(r2);
		return r1;
	}
	else if(temp2 != NULL) {
		loc = temp2->binding;
		fprintf(outfile,"MOV R%d, BP\n",r1);
		fprintf(outfile,"MOV R%d, %d\n",r2,loc);
		fprintf(outfile,"ADD R%d, R%d\n",r1,r2);
		freereg(r2);
		return r1;
	}
	else if(temp1 != NULL) {
		loc = temp1->binding;
		fprintf(outfile,"MOV R%d, %d\n",r1,loc);
		freereg(r2);
		return r1;
	}
}

int codegen(struct tree_node *head,FILE * outfile)
{
	struct tree_node *temp=NULL;
	int r,r1,r2,loc,l1,l2,i,j,argcount1=0;
	if(head == NULL) {
		printf("error in codegen");
		yyerror();
	}
	else if(head->nodetype == NUM){
		r = getreg();
		fprintf(outfile,"MOV R%d, %d\n",r,head->value);
		return r;
	}
	else if(head->nodetype == ID){
		r=getreg();
		r1=getbind(head->name);
		fprintf(outfile,"MOV R%d [R%d]\n",r,r1);
		freereg(r1);
		return r;
	}
	else if(head->nodetype == ID_REF) {
		r = getbind(head->name);
//		r1 =getreg();
//		fprintf(outfile,"MOV R%d, BP\n",r1);
//		fprintf(outfile,"SUB R%d, R%d\n",r,r1);
//		freereg(r1);
		return r;
	}
	else if(head->nodetype == ID_ARRAY_REF) {
		r1=getreg();
		r2=codegen(head->l,outfile);
		r=getreg();
		loc = head->Gentry->binding;
		fprintf(outfile,"MOV R%d %d\n",r,loc);
		fprintf(outfile,"ADD R%d R%d\n",r2,r);
		fprintf(outfile,"MOV R%d R%d\n",r1,r2);
		freereg(r2);
		freereg(r);
		return r1;
	}
	else if(head->nodetype == ID_ARRAY){
		r1=getreg();
		r2=codegen(head->l,outfile);
		r=getreg();
		loc = head->Gentry->binding;
		fprintf(outfile,"MOV R%d %d\n",r,loc);
		fprintf(outfile,"ADD R%d R%d\n",r2,r);
		fprintf(outfile,"MOV R%d [R%d]\n",r1,r2);
		freereg(r2);
		freereg(r);
		return r1;
	}
	else if(head->nodetype == TRUE){
		r = getreg();
		fprintf(outfile,"MOV R%d 1\n",r);
		return r;
	}
	else if(head->nodetype == FALSE){
		r = getreg();
		fprintf(outfile,"MOV R%d 0\n",r);
		return r;
	}
	else if(head->nodetype == '+'){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"ADD R%d R%d\n",r1,r2);
		freereg(r2);
		return r1;
	}
	else if(head->nodetype == '-'){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"SUB R%d R%d\n",r1,r2);
		freereg(r2);
		return r1;
	}	
	else if(head->nodetype == '*'){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"MUL R%d R%d\n",r1,r2);
		freereg(r2);
		return r1;
	}
	else if(head->nodetype == '/'){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"DIV R%d R%d\n",r1,r2);
		freereg(r2);
		return r1;
	}
	else if(head->nodetype == '%'){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"MOD R%d R%d\n",r1,r2);
		freereg(r2);
		return r1;
	}
	else if(head->nodetype == LT){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"LT R%d R%d\n",r1,r2);
		freereg(r2);
		return r1;
	}
	else if(head->nodetype == LE){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"LE R%d R%d\n",r1,r2);
		freereg(r2);
		return r1;
	}
	else if(head->nodetype == GT){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"GT R%d R%d\n",r1,r2);
		freereg(r2);
		return r1;
	}
	else if(head->nodetype == GE){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"GE R%d R%d\n",r1,r2);
		freereg(r2);
		return r1;
	}
	else if(head->nodetype == EQ){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"EQ R%d R%d\n",r1,r2);
		freereg(r2);
		return (r1);
	}
	else if(head->nodetype == NE){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"NE R%d R%d\n",r1,r2);
		freereg(r2);
		return (r1);
	}
	else if(head->nodetype == AND){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"MUL R%d R%d\n",r1,r2);
		freereg(r2);
		return (r1);
	}
	else if(head->nodetype == OR){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"ADD R%d R%d\n",r1,r2);
		fprintf(outfile,"MOV R%d 0\n",r2);
		fprintf(outfile,"GT R%d R%d\n",r1,r2);
		freereg(r2);
		return (r1);
	}
	else if(head->nodetype == NOT){
		r1 = codegen(head->l,outfile);					
		r2 = getreg();
		fprintf(outfile,"MOV R%d 0",r2);
		fprintf(outfile,"EQ R%d R%d\n",r1,r2);
		freereg(r2);
		return (r1);
	}
	else if(head->nodetype == 3){
		codegen(head->l,outfile);
		codegen(head->r,outfile);
		return free_reg;
	}
	else if(head->nodetype == '='){

		r = codegen(head->r,outfile);
		if(head->l->nodetype == ID){
			r1=getbind(head->l->name);
			fprintf(outfile,"MOV [R%d] R%d\n",r1,r);
			freereg(r1);
		}
		else{
			loc = head->l->Gentry->binding;
			r1 = codegen(head->l->l,outfile);
			r2 = getreg();
			fprintf(outfile,"MOV R%d %d\n",r2,loc);
			fprintf(outfile,"ADD R%d R%d\n",r1,r2);
			fprintf(outfile,"MOV [R%d] R%d\n",r1,r);		
			freereg(r2);
			freereg(r1);
		}
		freereg(r);
		return free_reg;
	}
	else if(head->nodetype == READ)
	{
		r = getreg();
		fprintf(outfile,"IN R%d\n",r);
		if(head->l->nodetype == ID){
			r1=getbind(head->l->name);
			fprintf(outfile,"MOV [R%d] R%d\n",r1,r);
			freereg(r1);
		}
		if(head->l->nodetype == ID_ARRAY){
			loc = head->l->Gentry->binding;
			r1 = codegen(head->l->l,outfile);
			r2 = getreg();
			fprintf(outfile,"MOV R%d %d\n",r2,loc);
			fprintf(outfile,"ADD R%d R%d\n",r1,r2);
			fprintf(outfile,"MOV [R%d] R%d\n",r1,r);		
			freereg(r2);
			freereg(r1);
		}

		freereg(r);
		return free_reg;
	}
	else if(head->nodetype == WRITE)
	{
		r = codegen(head->l,outfile);
		fprintf(outfile,"OUT R%d\n",r);
		freereg(r);
		return free_reg;
	}
	else if(head->nodetype == IF)
	{
		l1 = getlabel();
		r1 = codegen(head->l,outfile);
		freereg(r1);
		fprintf(outfile,"JZ R%d l%d\n",r1,l1);
		r1 = codegen(head->m,outfile);
		if(r1 == -1)
			r1 = getreg();
		fprintf(outfile,"l%d: \n",l1);
		freereg(r1);
		return free_reg;
	}
	else if(head->nodetype == ELSE)
	{
		l1 = getlabel();
		l2 = getlabel();
		r1 = codegen(head->l,outfile);
		freereg(r1);
		fprintf(outfile,"JZ R%d, l%d\n",r1,l1);
		r1 = codegen(head->m,outfile);
		fprintf(outfile,"JMP l%d\n",l2);
/*		if(r1 != -1){
			printf("error in else\n");
			yyerror();						check later
		}*/
		fprintf(outfile,"l%d: \n",l1);
		r1 = codegen(head->r, outfile);
		fprintf(outfile,"l%d: \n",l2);
		return free_reg;
	}
	else if(head->nodetype == WHILE)
	{
		l1=getlabel();
		l2 = getlabel();
		fprintf(outfile,"l%d: \n",l1);
		r1 = codegen(head->l,outfile);
		freereg(r1);
		fprintf(outfile,"JZ R%d l%d\n",r1,l2);
		r1 = codegen(head->m,outfile);
		if(r1 == -1)
			r1 = getreg();
		fprintf(outfile,"JMP l%d\n",l1);
		fprintf(outfile,"l%d: \n",l2);
		freereg(r1);
		return free_reg;
	}
	else if(head->nodetype == FUNCT) {
		temp = head;
		for(i=0;i<=free_reg;i++) {
			fprintf(outfile,"PUSH R%d\n",i);
		}
		temp = temp->l;
		while(temp != NULL && temp->r != NULL) {
			r1 = codegen(temp->r,outfile);
			fprintf(outfile,"PUSH R%d\n",r1);
			freereg(r1);
			temp = temp->l;
			argcount1++;
		}
		fprintf(outfile,"PUSH R0\n");
		fprintf(outfile,"CALL %s \n",head->name);

		r=getreg();
		fprintf(outfile,"POP R%d\n",r);
		r2=getreg();

		for(j=0;j<argcount1;j++)
			fprintf(outfile,"POP R%d\n",r2);
		freereg(r2);

		for(j=i-1;j>-1;j--)
			fprintf(outfile,"POP R%d\n",j);
		return r;
	}
}

yyerror()
{
	printf("\nerror in line no %d\n",line_count+1);
	exit(1);
}

int main(int argc, char* argv[])
{
	outfile = fopen("output","w");
	yyin = fopen(argv[1],"r");
	yyparse();
	fclose(yyin);
	return 1;
}
