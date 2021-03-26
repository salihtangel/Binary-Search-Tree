#include <stdio.h>

//this function finds the digit of number
int find_digit(int number_digit){
        
    int i = 0;
    if(number_digit <0){
        
        number_digit *= -1;
    }
    while(number_digit  >   0){

        number_digit /= 10;
        i++;        //counting digit
    }
    
    return  i;
}
//in here we have some implemantations.The names tell their missions
int main()
{
    FILE* fptr=NULL;
    int search_number,compare_number,counter=0,digit=0;
    long int adress_keeper;


//In here we are openning the file
    fptr=fopen("file.txt","r+");
    if(fptr==NULL){
        fprintf(stderr,"Error!\n");
	return 0;
    }
    
//Here we have 2 while loop and one of them for searching other one for comparing.
    while (fscanf(fptr,"%d",&search_number) && !feof(fptr))
    {
        adress_keeper=ftell(fptr);

	
        while(fscanf(fptr,"%d",&compare_number) && !feof(fptr))
        {
		    //It means that match found
            if(compare_number==search_number)
            {
                //The most important thing is here.We are finding how many digits we have.
                digit	=	find_digit(compare_number);
               // This comment  statement is only for to check is it finding compare number true.If you wish you can open it.
               // printf("compare num:%d\n\n\n",compare_number);
               
               //we come back to the cursor as much as we need
                fseek(fptr,-1*(digit),SEEK_CUR);
		        
                //And then we are deleting with printing empty character
                 for(;digit > counter++;){
                    fprintf(fptr,"%c",' ');
                 }	

            }
            counter=0;
        }
        //To skip numbers which we have already checked 
        fseek(fptr,adress_keeper,SEEK_SET);
    }
    fclose(fptr);
    return 1;
}
