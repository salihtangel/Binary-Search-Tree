#include<stdio.h> 

//swap function
void swap(int *xp, int *yp) 
{ 
int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}
// In here i used a selectionsort because i want to count my numbers clearly
// if i do not use selection sort i cannot go forward with cursor , i should come back first element again and again 
// and there is no need to do selection sort you ca use any type of sortage
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
    // we are doing a sort every tour after that we  are decreasing one from all list
    // The number which we do not need is minumum number after every tour 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
        swap(&arr[min_idx], &arr[i]); 
    } 
} 


int main(){
        int  text[100];      //for record normal numbers(all of them)
        int  text2[100];     //for repeated numbers
        int  text3[100];    //for how many times our numbers are repeating;
        int count =0;
        int count2 =0;
        int count3 = 0;
        int repeat =0 ;     //how many times our number is repeating
        FILE*fp;

        fp= fopen("input.txt","r");
        if(fp == NULL){
                 printf("Emty file");
                 return 0;
        }
     
        while(!feof(fp)){
            count2 = count;
            if(fscanf(fp,"%d",&text[count++]))
                 {

                         printf("%d\n",text[count2]);
 

                }
        }

        selectionSort(text,count);
        
printf("\n\n\n");

// In here we are starting
        int i = 0;
        count2=0;
        //we are using  'count' for limiting the numbers
        while(  i       <  count){

            count2 = i+1;
            while(count2    <   count  )//In here we are checking just one number(i) with all numbers(count2).
            
            {
                
                //'i'  is constant in inside while but in the outside while  it is increasing
                if(text[i]    ==    text[count2] )
                {
                        repeat++;// if it repeats we are adding plus one to repeat 
                        if(repeat > 0 ){
                            
                            text2[count3]    =        text[count2];   //we copied that repeated number
                        }         
               
                }
             
                count2++;
            }
                
                count2=0;//we will use again so we should do zero 'count2'
                i+= repeat;//this is for skip numbers which we have already checked because the numbers are increasig in order.
                if (repeat == 0) i++;// if it is not repeated we should move cursor
                if(repeat>0){
                   
                    printf("%d\n",text2[count3]);
                    printf("%d\n",text3[count3]);
 		    text3[count3] = ++repeat;  //we copied how many times this number is repeating;
                    count3++;// this is for  recording the repeating numbers;
                   
                }                  
                repeat = 0;
         } 
        fclose(fp);

        // In here we will do output.txt
        fp= fopen("output.txt","w");
                if(fp == NULL){
                         printf("Emty file");
                         return 0;
                }
        printf("i:%d  count:%d\n",i,count);
         i  = 0;
         count = 0;
         //we will use count3 for limiting  how many different  types  number we have  and i for seeing  numbers;
         while(!feof(fp)    &&  i   <   count3){
            count = i;
            if(fprintf(fp,"%d:\t",text2[count])    &&       fprintf(fp,"%d\n",text3[count]))
                 {
                         i++;
                         //to see before number
                         printf("num:%d:\t",text2[count]);
                         printf("rep times:%d\n",text3[count]);

                }
        }
        fclose(fp);
        return 0;
}
