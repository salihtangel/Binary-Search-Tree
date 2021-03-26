#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
//NOTE STRTOK STRING ILK GORDUGUKARAKTERE KADAR PARCALIYO
typedef  enum{INPUT,AND,OR,NOT,FLIPFLOP}a;
typedef struct node
{
	int *gate;/*to record and1 or1 ...*/
	int *user_input;/*to record a b c d...*/
	char text[MAX][MAX];/*to record every word in one sentence*/


}operator;
int main()
{
	int read;
	char *ctxt;/*for reading circuit.txt*/
	char *itxt;/*for reading input.txt*/
	char *record;
	char *record2;/*to use of strcat*/
	FILE *fp;
	int i,j,k;
	char * token;
	const char s[2]=" ";
	operator input;
	
	input.user_input = malloc(sizeof(char*));
	input.gate  = malloc(sizeof(char*));
	record=malloc(MAX*sizeof(char*));			//example arr = malloc(sizeof(int*) * row);	
	
	//record  = (char*)realloc(record,j+1);


	int counter=0;/*for counting number of empty places*/

	fp = fopen("input.txt","r");/*openning input file*/
	if(fp == NULL)
	{
		printf("it cannot be opened\n");
		return -1;
	}
	itxt=malloc(sizeof(char*));
	itxt=realloc(itxt,MAX	*sizeof*itxt);
	fgets(itxt,MAX,fp);
	fclose(fp);

	fp = fopen("circuit.txt","r");/*openning circuit file*/
	if(fp == NULL)
	{
		printf("it cannot be opened\n");
		return -1;
	}
	ctxt=malloc(sizeof(char*));/*allocation for circuit.txt*/
	i=0,j=0;
	
	
	while(!feof(fp))
	{
		k=strlen(ctxt)+1;
		ctxt[k]=' ';

		//printf("ctxt:%s",ctxt);
		fgets(ctxt,MAX,fp);
		/* get the first token */
		   token = strtok(ctxt, s);
		 /* walk through other tokens */
		  i=0;
		 while( token != NULL ) {
		      printf( " result0:%s	", token );
		      strcpy(input.text[i],token);
		      token = strtok(NULL, s);
		     // printf("last:%s	\n",input.text[i]);
		      i++;
		 }

	}
	i=0;
	while(i !=20)
	{	printf("son:%s	",input.text[i]);
		i++;
	}
	//printf("%s	",input.text[2]);
	//printf("%s	",input.text[3]);
	//printf("%s	",input.text[4]);
	//printf("%s	",input.text[5]);
	fclose(fp);
	/*while(!feof(fp))
	{

	fgets(ctxt,MAX,fp);
	ctxt=realloc(ctxt,MAX*sizeof*ctxt);
	k=strlen(ctxt)+1;
	ctxt[k]=' ';
	printf("ctxt:%s",ctxt);
	k=0;
	int size = 0;
	for(i=0,j=0;ctxt[j] != '\0';j++)
	{

		if(ctxt[j]==' ')
		{
			counter++;
			record  = malloc(MAX*sizeof(char*));
			i++;
		}
		if(counter == 1 )
		{
		 record[i][j]=ctxt[j];
		// printf("%c\n",record[j]);
		}
		else if(counter == 2 )
		{	
		 record[i][j]=ctxt[j];
		 //printf("%c\n",record[j]);
		}
		else if(counter == 3 )
		{	
		 record[i][j]=ctxt[j];
		 //printf("%c\n",record[j]);
		}
		else if(counter == 4 )
		{	
		 record[i][j]=ctxt[j];
		 //printf("%c\n",record[j]);
		}

	}
	counter = 0;//for other line counter must be 0
	if(ctxt[0] == 'I')
		read = 0;
	else if(ctxt[0] == 'A'){
		read =1;
	}
	else if(ctxt[0] == 'O'){
		read =2;
	}
	else if(ctxt[0] == 'N'){
		read =3;
	}
	else if(ctxt[0] == 'F'){
		read =4;
	}

		switch(read)
		{
			case INPUT:
			{ 	i=0;
                                while(*itxt != '\n')
                                {       if(*itxt==' ')
                                                itxt++;
                                        else if(*itxt=='1' || *itxt=='0')
                                        {
                                                input.user_input[i]=atoi(itxt);
                                                itxt++;
						i++;
						input.user_input=realloc(input.user_input,1);
                                        }
                                }
				break;
			}
			case AND://burda kaldin isme gore analiz ve record cok bosluklu aliyo
				i=0;
				//printf("a.:%s\n",record);
				//if(recor)
				break;
			case OR:
				
				//printf("o.:%s\n",record);
				break;
			case NOT:
				//printf("n.:%s\n",record);
				break;
			case FLIPFLOP:
				break;
			
		}

	}*/
	fclose(fp);
	return 0;
}
