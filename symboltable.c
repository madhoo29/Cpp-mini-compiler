#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
/*#include "yy.tab.h"*/

typedef struct SYM{
	char* name;
	char* value;
	int line;
	int used_lines[10];
	int declared;
	int num;
	int type;
	struct SYM* next;
}sym;	

typedef struct scope_head{
	sym* vars;
	int scope;
}scope_head;	// points to the variables declared in the given scope

scope_head* table[20]; //stack
int i = 0; //stack pointer

void display(){
	printf("NAME\tTYPE\tVALUE\tLINE\tSCOPE\n");
	scope_head* temp = table[i-1];
	int c = i - 1;
	// while(c >= 0){
		sym* node = temp->vars;
		while(node != NULL){
			char* type;
			//printf("start %d\n", node->type);
			switch (node->type){
				case 1: type = "int"; printf("%s\t%s\t%d\t%d\t%d\n",node->name, type, atoi(node->value), node->line, c); break;
				case 2: type = "double"; printf("%s\t%s\t%f\t%d\t%d\n",node->name, type, atof(node->value), node->line, c); break; 
				case 3: type = "void"; printf("%s\t%s\tVOID\t%d\t%d\n",node->name, type, node->line, c); break; 
				case 4: type = "char"; printf("%s\t%s\t%c\t%d\t%d\n",node->name, type, *(node->value+1), node->line, c);  break;
				case 5: type = "string"; printf("%s\t%s\t%s\t%d\t%d\n",node->name, type, (node->value), node->line, c); break;
			}
			node = node->next;
		}

		// c--;
		// temp = table[c];
	// }
}

sym* create_var(char* name, int line, int type){
	sym* new = (sym*)malloc(sizeof(sym));
	new->name = (char*)malloc(sizeof(char) * strlen(name));
	strcpy(new->name, name);
	new->line = line;
	new->value = NULL;
	new->num = 0;
	new->declared;
	new->type = type;
	new->next = NULL;
	return new;
}

void push(scope_head* node){
	if(table[i] != NULL)
		free(table[i]);
	table[i++] = node;
}

void pop(){
	display();
	if(table[i - 1]->vars == NULL){
		free(table[i--]);
		return;
	}
	if(table[i - 1]->vars->next == NULL){
		free(table[i - 1]->vars->next);
		free(table[i - 1]->vars);
	}
	else{
		sym* temp = table[i - 1]->vars->next;
		sym* prev = table[i - 1]->vars;
		while(temp != NULL){
			prev->next = temp->next;
			free(temp);
			temp = prev->next;
		}
		free(table[i - 1]->vars);
	}
	free(table[i--]);
}

int lookup(char* name, int scope, int type, int line){ // declarations only
	if(scope == table[i - 1]->scope){
		sym* temp = table[i - 1]->vars;
		while(temp != NULL){
			if(strcmp(temp->name, name) == 0){
				return 0; // redeclaration error
			}
			temp = temp->next;
		}
		sym* new = create_var(name,line,type);
		new->name = name;
		new->type = type;
		//printf("lname : %s\n", name);
		new->declared = line;
		new->value = NULL;
		new->line = line;
		if(temp == NULL){
			new->next = table[i - 1]->vars;
			table[i - 1]->vars = new;
		}
		else
			temp->next = new;
		return 1; // no error
	}
	
	// scope_head* node = (scope_head*)malloc(sizeof(scope_head));
	// node->scope = scope;
	// node->vars = NULL;
	// push(node);
}

#if 0
//int check(char* name, int scope, int type, int line, int value){ // usage 
int check(char* name, int scope, int line, int value){ // usage 
	index = i;
	while(index > 0){
		sym* temp = table[index]->vars;
		while(temp != NULL && temp->next != NULL){
			if(strcmp(temp->name, name) == 0){
				// yyerror("Redeclaration of variable %s", name);
				temp->used_lines[temp->num++] = line;
				temp->value = value;
				return 1; // no error
			}
			temp = temp->next;
		}
		index--;
	}
	return 0; // no declaration error
}
#endif

int check(char* name, int scope, int line, char* value){ // usage 
	int index = i - 1;
	while(index >= 0){
		sym* temp = table[index]->vars;
		while(temp != NULL){
			if(strcmp(temp->name, name) == 0){
				temp->used_lines[temp->num++] = line;
				temp->value = value;
				// printf("name : %s\n", temp->value);

				return 1; // no error
			}
			temp = temp->next;
		}
		index--;
	}
	return 0; // no declaration error
}	

void enter_scope(int scope){
	scope_head* new = (scope_head*)malloc(sizeof(scope_head));
	new->vars = NULL;
	new->scope = scope;
	push(new);
	//display();
}

void exit_scope(int scope){
		pop();

		//printf("unidentified error\n");
}

void init(){
	int n = 0;
	for(int n = 0; n < 20; ++n){
		table[i] = NULL;
	}
	enter_scope(0);
}

#if 0
int main(){
	//init();
	char* type;
	type = "int";
	printf("%s",type);
	printf("done\n");
	enter_scope(0);
	printf("done2\n");
	lookup("ab",0,1,4);
	check("ab",0,3,"0");
	display();
}
#endif









