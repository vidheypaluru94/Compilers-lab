struct Argstruct 
{
	int type;
	char *name;
	int passby;
	int argbind;
	struct Argstruct *next;
};

struct Gsymbol {
	char *name;
	int type;
	int size;
	int nodetype;
	int binding;
	struct Argstruct *arglist;
	struct Gsymbol *next;
};

struct Lsymbol {
	char *name;
	int type;
	int binding;
	struct Lsymbol *next;
};

extern struct Gsymbol *Gsymbol_Table;
extern struct Lsymbol *Lsymbol_Table;
extern struct Argstruct *Arg_List;

struct Gsymbol * Glookup(char *name);
void Ginstall(char *name,int type,int size,int nodetype, struct Argstruct *arglist);

struct Lsymbol * Llookup(char *name);
void Linstall (char *name, int type);

void Arginstall(int type, int passby, char *name);
struct Argstruct* Arglookup(char *name);