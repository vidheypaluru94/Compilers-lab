struct tree_node {
	int type;
	int nodetype;
	char *name;
	int value;
	struct tree_node *l;
	struct tree_node *m;
	struct tree_node *r;
	struct Gsymbol *Gentry;
	struct Lsymbol *Lentry;
};

struct tree_node* makenode(int ,int , char *, int , struct tree_node *,struct tree_node*, struct tree_node*);

void print_in(struct tree_node *);

void print_pre(struct tree_node *);
