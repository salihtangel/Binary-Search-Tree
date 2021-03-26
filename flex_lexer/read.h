#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *fun_parse(char a[],FILE *fptr)
{
   const char s[1] = " ";
   char *token;
   
   /* get the first token */
   token = strtok(a, s);
   
   /* walk through other tokens */
   while( token != NULL ) {
	fun(token,fptr);
    
      token = strtok(NULL, s);

}

}
char * fun_add_space(char a[])
{
char temp[10000];
int i=0;

while(a[i] != '\0'){
	if(a[i]==')' || a[i]=='('){
		if(a[i+1] != ' '){
			strcpy(temp,&a[i+1]);
			a[i+1]=' ';
			strcpy(&a[i+2],temp);
		}
	}
	if(a[i]==')' || a[i]=='(' ){
		if(a[i-1] != ' '){
			strcpy(temp,&a[i]);
			a[i]=' ';
			strcpy(&a[i+1],temp);
		}
	}
	i++;
}
	return a;
}

void  fun_read(){
char temp[10000];
char outputfile[100000];
char filename[100];
int flag=0;
char comment =';';
char empty;
printf("please enter a filename\n");
scanf("%s",filename);
int i=0;

FILE *fptr = fopen("parsed_cpp.txt","w");
FILE *f = fopen(filename, "r");
   int c = getc(f);
   while (c != EOF) {
      if(c == comment)
	      flag++;
      if(flag == 2){	//COMMENT LINE ICIN
	      fprintf(fptr, "COMMENT\n");
	      empty=c;
	      while( c != '\n') {
	      		c = getc(f);
		}
	      flag=0;
      }
      temp[i]=c;
      c = getc(f);
      i++;
   }
   if (feof(f)){
	fun_add_space(temp);// bosluk atip alt satirda parse yapmaya gidiyor
	fun_parse(temp,fptr);
   }
   else
   fclose(f);
   getchar();
   exit(0);
}
