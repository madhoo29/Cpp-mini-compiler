#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
/*#include "yy.tab.h"*/

typedef struct SYM{
	char* name;
	int value;
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
	scope_head* temp = table[i];
	int c = i;
	while(c >= 0){
		sym* node = temp->vars;
		while(node != NULL){
			printf("%s %d\n",node->name, c);
			node = node->next;
		}
		c--;
		temp = table[c];
	}
}

sym* create_var(char* name, int line, int type){
	sym* new = (sym*)malloc(sizeof(sym));
	new->name = (char*)malloc(sizeof(char) * strlen(name));
	strcpy(new->name, name);
	new->line = line;
	new->value = INT_MIN;
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
	if(table[i]->vars == NULL){
		free(table[i--]);
		return;
	}
	if(table[i]->vars->next == NULL){
		free(table[i]->vars->next);
		free(table[i]->vars);
	}
	else{
		sym* temp = table[i]->vars->next;
		sym* prev = table[i]->vars;
		while(temp != NULL){
			prev->next = temp->next;
			free(temp);
			temp = prev->next;
		}
		free(table[i]->vars);
	}
	free(table[i--]);
}

int lookup(char* name, int scope, int type, int line){ // declarations only
	if(scope == table[i]->scope){
		sym* temp = table[i]->vars;
		while(temp != NULL && temp->next != NULL){
			if(strcmp(temp->name, name) == 0){
				// yyerror("Redeclaration of variable %s", name);
				return 0; // redeclaration error
			}
			temp = temp->next;
		}
		sym* new = create_var(name,line,type);
		new->declared = line;
		if(temp == NULL)
			table[i]->vars = new;
		else
			temp->next = new;
		return 1; // no error
	}
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

int check(char* name, int scope, int line){ // usage 
	int index = i;
	while(index > 0){
		sym* temp = table[index]->vars;
		while(temp != NULL && temp->next != NULL){
			if(strcmp(temp->name, name) == 0){
				// yyerror("Redeclaration of variable %s", name);
				temp->used_lines[temp->num++] = line;
				return 1; // no error
			}
			temp = temp->next;
		}
		index--;
	}
	return 0; // no declaration error
}	

void enter_scope(int scope){
	display();
	scope_head* new = (scope_head*)malloc(sizeof(scope_head));
	new->vars = NULL;
	new->scope = scope;
	push(new);
}

void exit_scope(int scope){
	display();
	if(table[i]->scope == scope)
		pop();
	else
		printf("unidentified error\n");
}









