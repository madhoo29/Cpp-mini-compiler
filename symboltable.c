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
	//int used_lines[10];
	int declared;
	int num;
	int type;
	int scope;
	struct SYM* next;
}sym;

typedef struct scope_head{
	sym* vars;
	int scope;
}scope_head;	// points to the variables declared in the given scope

scope_head* table[20]; //stack
int i = 0; //stack pointer
sym* global_table;
sym* link;


void display(){
	FILE* ptr = fopen("op.txt","w");
	fprintf(ptr,"%-8s\t\t%-8s\t\t%-8s\t\t%-8s\t\t%-8s\n\n","NAME","TYPE","VALUE","LINE","SCOPE");
	sym* node = global_table;
	while(node != NULL){
		char* type;

		if(node->arr != NULL){
			fprintf(ptr,"%-8s\t\t%-8s\t\t",node->name,(node->type==1)?"int*":"char*");
			int l = atoi(node->value);
			int len = 0;
			while(len < l){
				int found = 0;
				anode* tmp = node->arr;
				while(tmp != NULL){
					if(tmp->index == len){
						printf("ggg\n");
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
			fprintf(ptr,"\t\t%-8d\t\t%-8d\n",node->line, node->scope);
		}

		else{
		switch (node->type){
			case 1: type = "int"; fprintf(ptr,"%-8s\t\t%-8s\t\t%-8s\t\t%-8d\t\t%-8d\n",node->name, type, (node->value), node->line, node->scope); break;
			case 2: type = "double"; fprintf(ptr,"%-8s\t\t%-8s\t\t%-8s\t\t%-8d\t\t%-8d\n",node->name, type, (node->value), node->line, node->scope); break; 
			case 3: type = "void"; fprintf(ptr,"%-8s\t\t%-8s\t\tVOID\t\t%-8d\t\t%-8d\n",node->name, type, node->line, node->scope); break; 
			case 4: type = "char"; fprintf(ptr,"%-8s\t\t%-8s\t\t%-8s\t\t%-8d\t\t%-8d\n",node->name, type, (node->value), node->line, node->scope);  break;
			case 5: type = "string"; fprintf(ptr,"%-8s\t\t%-8s\t\t%-8s\t\t%-8d\t\t%-8d\n",node->name, type, (node->value), node->line, node->scope); break;
		}
		}
		node = node->next;
	}
	fprintf(ptr,"\n\n\n");
	fclose(ptr);
}


sym* create_var(char* name, int line, int type, int scope){
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
	new->scope = scope;
	return new;
}

void push(scope_head* node){
	if(table[i] != NULL)
		free(table[i]);
	table[i++] = node;
}

void pop(){
	sym* temp = table[i - 1]->vars;
	while(temp != NULL){
		sym* temp2 = temp->next;
		temp->next = global_table;
		global_table = temp;
		temp = temp2;
	}
	table[i] = NULL;
	free(table[i--]);
}

int lookup(char* name, int scope, int type, int line){ // declarations only
	if(scope == table[i - 1]->scope){
		sym* temp = table[i - 1]->vars;
		sym* prev = NULL;
		while(temp != NULL){
			if(strcmp(temp->name, name) == 0){
				link = temp;
				return 0; // redeclaration error
			}
			prev = temp;
			temp = temp->next;
		}
		sym* new = create_var(name,line,type,scope);
		//printf("lname : %s\n", name);
		new->declared = line;
		new->value = NULL;
		new->arr = NULL;
		if(prev == NULL){
			new->next = table[i - 1]->vars;
			table[i - 1]->vars = new;
		}
		else
		{
			prev->next = new;
		}
		link = new;
		return 1; // no error
	}
}

int lookup_arr(char* name, int scope, int type, int line, char* length){ // declarations only
	if(scope == table[i - 1]->scope){
		sym* temp = table[i - 1]->vars;
		sym* prev = NULL;
		while(temp != NULL){
			if(strcmp(temp->name, name) == 0){
				return 0; // redeclaration error
			}
			prev = temp;
			temp = temp->next;
		}
		sym* new = create_var(name,line,type,scope);
		new->name = name;
		new->type = type;
		new->declared = line;
		new->value = length; //value holds length of arr
		new->arr = (anode*)malloc(sizeof(anode));
		new->arr->index = -1;
		new->arr->next = NULL;
		new->line = line;
		if(prev == NULL){
			
			new->next = table[i - 1]->vars;
			table[i - 1]->vars = new;
		}
		else
			prev->next = new;
		link = new;
		return 1; // no error
	}
}

int check(char* name, int scope, int line, char* value){ // usage 
	int index = i - 1;
	while(index >= 0){
		sym* temp = table[index]->vars;
		while(temp != NULL){
			if(strcmp(temp->name, name) == 0){
				temp->value = value;
				link = temp;
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
				//temp->used_lines[temp->num++] = line;
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
				link = temp;
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
}

void exit_scope(int scope){
		pop();
}

void init(){
	int n = 0;
	for(int n = 0; n < 20; ++n){
		table[i] = NULL;
	}
	enter_scope(0);
}
