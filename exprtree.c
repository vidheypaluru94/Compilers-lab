#include<stdio.h>
#include<stdlib.h>
#include"exprtree.h"
#include"sym_table.h"

struct tree_node * makenode(int type, int nodetype, char *name, int value, struct tree_node *ptr1, struct tree_node *ptr2,struct tree_node *ptr3)
{
	struct tree_node *temp;
	struct Argstruct *temp1;
	temp=malloc(sizeof(struct tree_node));
	temp->type = type;
	temp->nodetype = nodetype;
	temp->name = name;
	temp->value = value;
	temp->l = ptr1;
	temp->m = ptr2;
	temp->r = ptr3;
	if(name != NULL)
	{
		temp->Lentry = Llookup(name);
		temp->Gentry = Glookup(name);				//changes to be done here//
		temp1 = Arglookup(name);

		if(temp->Gentry != NULL)
			temp->type = temp->Gentry->type;
		else if(temp->Lentry != NULL)
			temp->type = temp->Lentry->type;
		else if(temp1 != NULL)
			temp->type = temp1->type;
/*		if(temp->Gentry == NULL)
		{
			printf("variable not declared\n");
			yyerror();
		}
		temp->type = temp->Gentry->type;*/
	}
	else
		temp->Gentry = NULL;

	return temp;
}

void print_in(struct tree_node *head)
{
	if(head == NULL);
	else
	{
		print_in(head->l);
		if(head->nodetype == '0')
			printf("%d",head->type);
		else
			printf("%c",head->type);
		print_in(head->r);
	}
}

void print_pre(struct tree_node *head)
{
	if(head == NULL);
	else
	{
		if(head->nodetype == '0')
			printf("%d",head->type);
		else
			printf("%c",head->type);
		print_pre(head->l);
		print_pre(head->r);
	}
}
