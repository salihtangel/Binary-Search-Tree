	

all:

	gcc  bst.c -o run;


segment:
	gcc -g bst.c;
	gdb bst;


clear:
	gcc rm -o run;
