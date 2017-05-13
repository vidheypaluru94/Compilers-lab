#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"sym_table.h"
int start_addr = 0;
int sp = 0;
int Arg_bind=0;

struct Gsymbol *Gsymbol_Table = NULL;
struct Lsymbol *Lsymbol_Table = NULL;
struct Argstruct *Arg_List = NULL;

struct Gsymbol* Glookup(char *name)
{
	struct Gsymbol *head = Gsymbol_Table;
	while(head != NULL)
	{
		if(strcmp(head->name,name) == 0)
			break;
		else
			head=head->next;
	}
	return head;
}

void Ginstall(char *name,int type,int size,int nodetype, struct Argstruct *Arglist){
	struct Gsymbol *head = Gsymbol_Table,*temp=Gsymbol_Table;
	temp = Glookup(name);
	if(temp == NULL)
	{
		if(head == NULL){
			Gsymbol_Table = malloc(1*sizeof(struct Gsymbol));
			head = Gsymbol_Table;
		}
		else{
			while(head->next != NULL)
				head = head->next;
			head->next = malloc(1*sizeof(struct Gsymbol));
			head = head->next;
		}
		head->name = name;
		head->type = type;
		head->size = size;
		head->nodetype = nodetype;
		if(nodetype == 259)
			head->binding = 0;
		else
			head->binding = start_addr;
		start_addr += size;
		head->arglist = Arglist;
		head->next = NULL;
	}
	else
	{
		printf("error in declaration in Global Symbol Table\n");
		yyerror();
	}
}

struct Lsymbol * Llookup(char *name)
{
	/* data */
	struct Lsymbol *head = Lsymbol_Table;
	while(head!=NULL){
		if(strcmp(head->name,name) == 0)
			break;
		else
			head=head->next;
	}
	return head;
}

struct Argstruct * Arglookup(char *name) {
	struct Argstruct *head = Arg_List;
	while(head != NULL) {
		if(strcmp(head->name, name) == 0)
			break;
		else
			head = head->next;
	}
	return head;
}

void Linstall(char *name, int type)
{
	struct Lsymbol *head = Lsymbol_Table, *temp=NULL;
	struct Argstruct *temp2=NULL;
	temp = Llookup(name);
	temp2 = Arglookup(name);
	if(temp==NULL && temp2 == NULL){
		if(head == NULL){
			Lsymbol_Table = malloc(1*sizeof(struct Lsymbol));
			head = Lsymbol_Table;
		}
		else{
			while(head->next != NULL)
				head = head->next;
			head->next = malloc(1*sizeof(struct Lsymbol));
			head = head->next;
		}
		head->name = name;
		head->type = type;
		sp++;
		head->binding = sp;
		head->next = NULL;
	}
	else
	{
		printf("error in declaration\n");
		yyerror();
	}
}

/*void Arginstall(int type, int passby, char *name) {
	struct Argstruct *head=Arg_List,*temp = NULL;
	temp = Arglookup(name);
	if(temp == NULL){
		if(head == NULL){
			Arg_List = malloc(sizeof(struct Argstruct));
			head = Arg_List;
			head->name = name;
			head->type = type;
			head->passby = passby;
			Arg_bind++;
			head->argbind = Arg_bind;
			head->next = NULL;
		}
		else{
			temp = malloc(sizeof(struct Argstruct));
			temp->name = name;
			temp->type = type;
			temp->passby = passby;
			Arg_bind++;
			temp->argbind = Arg_bind;

			head = temp;
//			
/*			while(head->next != NULL)
				head = head->next;
			head->next = malloc(sizeof(struct Argstruct));
			head = head->next; */ 
/*		}
/*		head->name = name;
		head->type = type;
		head->passby = passby;
		Arg_bind++;
		head->argbind = Arg_bind;*/
//		head->next = NULL;
/*	}
	else {
		printf("error in arguments\n");
		yyerror();
	}
}*/
void Arginstall(int type, int passby, char *name) {
	struct Argstruct *head=Arg_List,*temp = NULL;
	temp = Arglookup(name);
	if(temp == NULL){
		temp = malloc(sizeof(struct Argstruct));
		temp->name = name;
		temp->type = type;
		temp->passby = passby;
		Arg_bind++;
		temp->argbind = Arg_bind;

		temp->next = Arg_List;
		Arg_List = temp;
	}
	else {
		printf("error in arguments\n");
		yyerror();
	}
}
