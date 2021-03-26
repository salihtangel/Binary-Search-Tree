#include<stdio.h>
#define MAX 251
int fun_seperate(char TEXT[MAX],int i,int j,int k,int paranthesies,char TEXT2[]){
	if(TEXT[i] == '\0')
		return 1;
	if(TEXT[i] == ')')
		paranthesies--;
	if(TEXT[i]=='(')
		paranthesies++;
	//it means that before cell probably is a character.
	if(TEXT[i]==','){
		//for a,b,c cases before comma must not be paranthesies
		if(TEXT[i-1]!= ')'){
			//this is a while loop till j equal to paranthesies
			while(paranthesies!=j){
				TEXT2[k++]='-';	
				j++;
			}
			TEXT2[k++]=TEXT[i-1];
			//printf("t1:%c\n",TEXT2[k-1]);
		
		}
		//for (a,b,c), cases
		else if(TEXT[i-1] == ')' && TEXT[i-2] != ')' && TEXT[i-1] != '(' && TEXT[i-3] == ',' ) {
			//this is a while loop till j equal to paranthesies
			paranthesies++;
			while(paranthesies!=j){
				TEXT2[k++]='-';	
				j++;
			}
			paranthesies--;
			TEXT2[k++]=TEXT[i-2];
			//printf("t2:%c\n\n",TEXT2[k-1]);
			//printf("i2:%c\n",TEXT2[i]);
		}
	}
	//for (a,a,(a),a,a) cases
	else if(TEXT[i+1] == ')'	&&	TEXT[i-1] == '('){
		while(paranthesies!=j){
			TEXT2[k++]='-';	
			j++;
		}
		TEXT2[k++]=TEXT[i];
		//printf("t3:%c\n",TEXT2[k-1]);
	}
	//it means that this character is the last one
	else if	(TEXT[i] != ')' && TEXT[i+1]!= ','		 &&		TEXT[i+2]!= ',' 	&&	TEXT[i+3]!= ',' 	&&	TEXT[i+4]!= ',' )
	{
		while(paranthesies!=j)
		{
			TEXT2[k++]='-';	
			j++;
		}
		TEXT2[k++]=TEXT[i];
		//printf("t4:%c\n\n",TEXT2[k-1]);
		//printf("i4:%c\n",TEXT2[i]);
	}
	fun_seperate(TEXT,++i,j=0,k,paranthesies,TEXT2);
}
//creating visualization
int prin_fun(char TEXT2[MAX],FILE *fp,int i){
	   if(TEXT2[i] == '\0') 
		      return 1;
	   if(TEXT2[i]== '-')
		fprintf(fp,"%c",TEXT2[i++]);
	   else{
		fprintf(fp,"%c\n",TEXT2[i++]);
	   }
	      prin_fun(TEXT2,fp,i);
}
int main(){
 
     int i,j,k,paranthesies;
     i=0,j=0,k=0,paranthesies=0;
     FILE *fp;
     char TEXT[MAX];
     char TEXT2[MAX];
     //first file reading
     fp = fopen("input.txt","r");
     if(fp == NULL){
            printf("it could no opened\n");
                    return 0;
     }
     i=0;
     while(!feof(fp)){
        fscanf(fp,"%c",&TEXT[i]);
        i++;
     }
     fclose(fp);
     //parsing part
     i=0;
     fun_seperate(TEXT,i,j,k,paranthesies,TEXT2);
     i=0;
      //another file printing results 
     fp= fopen("output.txt","w");
     if(fp == NULL){
        printf("it could no opened\n");
        return 0;
     } 
     prin_fun(TEXT2,fp,i);
     fclose(fp);
   return 1;
 }

