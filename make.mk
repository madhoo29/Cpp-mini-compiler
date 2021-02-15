all:
	flex compiler.l
	bison -d compiler.y
	gcc -o compiler compiler.tab.c lex.yy.c -g -ll
	

clean:
	rm -rf lex.yy.c compiler.tab.c compiler.tab.h compiler 

