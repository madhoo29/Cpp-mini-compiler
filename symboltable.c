#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
/*#include "yy.tab.h"*/

typedef struct ANODE{
	int i;
	char c;
	int index;
	struct ANODE* next;
}anode;

typedef struct SYM{
	char* name;
	char* value;
	anode* arr;
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
	FILE* ptr = fopen("op.txt","a");
	fprintf(ptr,"NAME\tTYPE\tVALUE\tLINE\tSCOPE\n");
	scope_head* temp = table[i-1];
	int c = i - 1;
		sym* node = temp->vars;
		while(node != NULL){
			
			char* type;

			if(node->arr != NULL){
				fprintf(ptr,"%s\t%s*\t",node->name,(node->type==1)?"int":"char");
				int l = atoi(node->value);
				int len = 0;
				while(len < l){
					int found = 0;
					anode* tmp = node->arr;
					while(tmp != NULL){
						if(tmp->index == len){
							found = 1;
							if(node->type == 4) fprintf(ptr,"%c ", tmp->c);
							else fprintf(ptr,"%d ", tmp->i);
						}
						tmp = tmp->next;
					}
					if(!found){
						if(node->type == 4) fprintf(ptr,"  ");
						else fprintf(ptr,"0 ");
					}
					len++;

				}
				fprintf(ptr,"\t%d\t%d\n",node->line, c);
			}

			else{
			switch (node->type){
				case 1: type = "int"; fprintf(ptr,"%s\t%s\t%d\t%d\t%d\n",node->name, type, atoi(node->value), node->line, c); break;
				case 2: type = "double"; fprintf(ptr,"%s\t%s\t%f\t%d\t%d\n",node->name, type, atof(node->value), node->line, c); break; 
				case 3: type = "void"; fprintf(ptr,"%s\t%s\tVOID\t%d\t%d\n",node->name, type, node->line, c); break; 
				case 4: type = "char"; fprintf(ptr,"%s\t%s\t%c\t%d\t%d\n",node->name, type, *(node->value+1), node->line, c);  break;
				case 5: type = "string"; fprintf(ptr,"%s\t%s\t%s\t%d\t%d\n",node->name, type, (node->value), node->line, c); break;
			}
			}
			node = node->next;
		}
		fprintf(ptr,"\n\n\n");
}

sym* create_var(char* name, int line, int type){
	sym* new = (sym*)malloc(sizeof(sym));
	new->name = (char*)malloc(sizeof(char) * strlen(name));
	strcpy(new->name, name);
	new->line = line;
	new->value = NULL;
	new->arr = NULL;
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
		new->arr = NULL;
		new->line = line;
		if(temp == NULL){
			new->next = table[i - 1]->vars;
			table[i - 1]->vars = new;
		}
		else
			temp->next = new;
		return 1; // no error
	}
}

int lookup_arr(char* name, int scope, int type, int line, char* length){ // declarations only
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
		new->value = length;
		new->arr = (anode*)malloc(sizeof(anode));
		new->arr->index = -1;
		new->arr->next = NULL;
		new->line = line;
		if(temp == NULL){
			new->next = table[i - 1]->vars;
			table[i - 1]->vars = new;
		}
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

int check_arr(char* name, int scope, int line, char* value, int aindex){ // usage 
	int index = i - 1;
	while(index >= 0){
		sym* temp = table[index]->vars;
		while(temp != NULL){
			if(strcmp(temp->name, name) == 0){
				temp->used_lines[temp->num++] = line;
				anode* new = (anode*)malloc(sizeof(anode));
				new->next = NULL;
				new->index = aindex;
				if(temp->type == 1)
					new->i = atoi(value);
				else if(temp->type == 4)
					new->c = *value;

				anode* t = temp->arr;
				while(t != NULL){
					if(t->index == aindex){
						if(temp->type == 1)
							t->i = atoi(value);
						else if(temp->type == 4)
							t->c = *value;						
						return 1;
					}
					t = t->next;
				}
				new->next = temp->arr;
				temp->arr = new;
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