//not working properly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 101

int fun_recursive(char *text,char*text2	,int len,char *object ,int i,int j ,int k,int partial,int cost,int value,int *len_number){
		len=strlen(text); 
		len_number[j]=len;//it is showing before string always
   		text = (char *) realloc(text, 100);//reallocation of memory
		
		gets(text2);//input from user
   		strcat(text,text2 );//copying text2 to end of text	



	while(text[i] != '\0')//main part adding and parsing
		{
			k=0;
			int star_counter=0;
			while(text[i+len+k] != '\0')
			{

				if(text[i+len+k] == '*')
					star_counter++;
				k++;
			}
			k=0;
			//to understand whether if user input is a price or not
			if(star_counter == 0)	//the case which is user writing the price		
			{

				printf("nu1:%s\n",text+len);

				value+=atoi(text+len);
				printf("value:%d\n",value);	
				
				//printf("i:%d\n",i);
				//printf("j:%d\n",len_number[j]);
				//printf("c%c",text[i+len]);

				text=text+i-len_number[j];//it must be come back in string but not working
				printf("text:%s\n",text);
				/*text[i+len]= len_number[j];

				j++;
				*/
			}
			else if(text[i+len] == '*')//the case finding *in string
			{

				k=0;
				printf("burasii\n");
				int z = i+len+k;
				printf("z%d\n",z);
				while(0 > z) // i must come back to first element of string
				{
					printf("hadiii\n");
					//Not working idk why? 
					if(57> text[i+len+k] && text[i+len+k]>48)//0 between 9 i ascii
					{
						printf("onemli\n");
						partial=atoi(text+len+k);
					}
					z--;
				}
				k=0;
				while(text[len+i+k] < 64)// must be bigger than  charcter A ascii
				{
					//printf("%c\n",text[len+i+k]);
					k++;
				}
				int counter = 0;
				while(text[len+i+k]!='+')
				{
					object[counter]=text[len+i+k];
					k++;
					counter++;
				}
				counter =0;
				printf(">What is  %s? \n",object);
				printf(">Partial  %d \n",partial);
				len=strlen(text); 
				len_number[j]=len;//len is always showing the end of the before string
				fun_recursive(text,text2 ,len,object,i,j,k,partial,cost,value,len_number);	
			}	
			star_counter=0;
			i++;
		}
	j++;

	return 1;
}
int main(){
	int *len_number;
	char *text;
	int cost = 0;
	int partial=0;
	int value = 0;
	char object[MAX];
	char text2[MAX];
	int i,j,k;
	int len;//i am using len for moving in pointer 100
	i=0;//for moving in one string
	j=1;//for recording len number

	text = (char*)malloc(MAX * sizeof(char));
		// allocated by malloc or not 
		 if (text == NULL) { 
			printf("Memory not allocated.\n"); 
			return -1;
		 }

	 len_number = (int*)malloc(MAX * sizeof(int)); 
  	 //object cannot be inside in the loop
	 printf("> Define the object:\n");
	 gets(object);
	 printf(">What is  %s ?\n",object);
	fun_recursive(text,text2 ,len,object,i,j,k,partial,cost,value,len_number);
	return 0;
}
