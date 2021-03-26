#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int counter =0;

int fun_check_value_or_identifier(char *x,FILE *fptr)
{	
	int i=0;
	int length=strlen(x);
	if(atoi(x) > 0 ){
		if(length > 1 && x[0] != '0'){
			for(int j=0;j<length;j++){
				if((58 > x[j]> 47)){
	      				fprintf(fptr, "ERROR\n");
					return 1;
				}
			}
	      		fprintf(fptr, "VALUE\n");
		}
		else if(length ==1)
			fprintf(fptr,"VALUE\n");
		else if(length > 1 && x[0] == '0')
			fprintf(fptr,"ERROR\n");

		return 1;
	}
	else if(!(58> x[i] >47) && x[i] != '\n'){
		fprintf(fptr,"IDENTIFIER	");
		fprintf(fptr," %c\n",x[i]);
		return 1;
	}
}

int fun(char *x,FILE *fptr)
{
if(0){}
	else if(!strcmp(x,"and")){ fprintf(fptr,"KW_AND\n");  return 0;  }
	else if (!strcmp(x,"or")){ fprintf(fptr,"KW_OR\n");	return 0;}
	else if (!strcmp(x,"not")){ fprintf(fptr,"KW_NOT\n");	return 0;}
	else if (!strcmp(x,"equal")){ fprintf(fptr,"KW_EQUAL\n");return 0;}
	else if (!strcmp(x,"less")){ fprintf(fptr,"KW_LESS\n"); return 0;}
	else if (!strcmp(x,"null")){ fprintf(fptr,"KW_NIL\n"); return 0;}
	else if (!strcmp(x,"list")){ fprintf(fptr,"KW_LIST\n"); return 0;}
	else if (!strcmp(x,"append")){ fprintf(fptr,"KW_APPEND\n"); return 0;}
	else if (!strcmp(x,"concat")){ fprintf(fptr,"KW_CONCAT\n"); return 0;}
	else if (!strcmp(x,"set")){fprintf(fptr,"KW_SET\n");	return 0;}
	else if (!strcmp(x,"deffun")){fprintf(fptr,"KW_DEFFUN\n");	return 0;}
	else if (!strcmp(x,"for")){fprintf(fptr,"KW_FOR\n");	return 0;}
	else if (!strcmp(x,"if")){fprintf(fptr,"KW_IF\n");	return 0;}
	else if (!strcmp(x,"exit")){fprintf(fptr,"KW_EXIT\n");	return 0;}
	else if (!strcmp(x,"load")){fprintf(fptr,"KW_LOAD\n");	return 0;}
	else if (!strcmp(x,"disp")){fprintf(fptr,"KW_DISP\n");	return 0;}
	else if (!strcmp(x,"true")){fprintf(fptr,"KW_TRUE\n");	return 0;}
	else if (!strcmp(x,"false")){fprintf(fptr,"KW_FALSE\n");return 0;}
	else if (!strcmp(x,"+")){fprintf(fptr,"OP_PLUS\n");return 0;}
	else if (!strcmp(x,"-")){fprintf(fptr,"OP_MINUS\n");return 0;}
	else if (!strcmp(x,"/")){fprintf(fptr,"OP_DIV\n");return 0;}
	else if (!strcmp(x,"*")){fprintf(fptr,"OP_MULTIP\n");return 0;}
	else if (!strcmp(x,"(")){fprintf(fptr,"OP_OP\n");return 0;}
	else if (!strcmp(x,")")){fprintf(fptr,"OP_CP\n");return 0;}
	else if (!strcmp(x,"**")){fprintf(fptr,"OP_DBLMULT\n");return 0;}
	else if (!strcmp(x,"\"")){
		if(counter == 0){
			fprintf(fptr,"OP_OC\n");
			counter++;
			return 0;
		}
		else if(counter == 1){
			fprintf(fptr,"OP_CC\n");
			counter=0;
			return 0;
		}
	}
	else if (!strcmp(x,",")){fprintf(fptr,"OP_COMMA\n");return 0;}
//	else if(!strcmp(x,";;")){printf("COMMENT\n");return 0;}
	fun_check_value_or_identifier(x,fptr);

}

