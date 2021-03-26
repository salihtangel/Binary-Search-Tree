#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 512
void  fun_decide_land(int cord[max][max],int i,int j,int water_level,int point,int land_number)
{
	while(i<512)										/*cheching upward*/
	{
		if(cord[i][j] > water_level)
		{
			cord[i][j] = land_number;
		}
		i++;
		if(cord[i][j] <= water_level)							/*check land  it going o stop*/
			i=512;
	}
	i=point;										/*to come back start point again*/
	while(i>-1)										/*checking downyard*/
	{
		if(cord[i][j] > water_level)
		{
			cord[i][j] = land_number;
		}
		i--;
		if(cord[i][j] <= water_level)							/* check land is going or stop*/
			i=-1;									
	}
}
int fun_find_land(int cord[max][max],int water_level,int i ,int j,int point ,int land_number)
{
	while(j< 513)											/*a loop for increase j every time*/
	{
		int k=0;
		if(j >= 511)										/*to increase i*/
		{
			j=0;
			i++;
		}
		if(i==512)										/*it means that problem is finished*/
		{
			FILE *fp;
			int k=0;
			fp=fopen("output.txt","w");
			if(fp == NULL)
			{
				printf("file could not opened");
				return -1;
			}
			fprintf(fp,"%d\n",(land_number+1)*-1);						/*to print first land number*/
			for(i=0;i<512;i++)
			{	for(j=0;j<512;j++)
				{
					if(cord[i][j]<0	 && cord[i][j] < k)
					{
						fprintf(fp,"%d	",cord[i][j]);	
						fprintf(fp,"x_coordinate1:%d	y_coordinate1:%d\n",i,j);
						k=cord[i][j];						/*to check if it is a same land or not*/
					}	
				}			
			}
			fclose(fp);

			return 0;
		}
		if(cord[i][j] > water_level)								/*the case we are in the land in first time */
		{
			while(cord[i][j] > water_level && j < 512) 
			{	
				point=i;								/* to not lose exact oint of j*/
				fun_decide_land(cord,i,j,water_level,point,land_number);
				j++;									/*to move forward in array*/
			}
			land_number--;									/*to distingush lands from each other*/
		}
		j++;
	}
	
	return -1;

}
void fun_fill_file(FILE *fp)
{
	int k=512*512;
	int i=0;
	srand(time(NULL));
	fprintf(fp,"%d\n",rand()%128+1);
	while(i < k)		
	{	
			fprintf(fp,"%d ",rand()%128+1);
			i++;
	}
}
int main()
{
	int i,j;
	int land_number =-1;
	int water_level;
	int read[max][max];			
	FILE *fp;
	int point;				/*to come back same y cordinate again*/
	/*fp=fopen("input.txt","w");		// random generate part 
	if(fp == NULL)
	{
		printf("file could not opened");
		return -1;
	}
	fun_fill_file(fp);
	fclose(fp);
	now it is starting
	*/
	fp=fopen("input.txt","r");
		if(fp == NULL)
		{
			printf("file could not opened");
			return -1;
		}
	fscanf(fp,"%d",&water_level);		/* i am reading water level and array in different time*/
	i=0;
	while(!feof(fp))
	{
		for(j=0;j<512;j++)
		{
			fscanf(fp,"%d",&read[i][j]);
		}

		++i;
	}
	fclose(fp);
	i=0,j=0;
	fun_find_land(read,water_level,i,j,point,land_number);
/*	
	for(i=0;i<512;i++)
	{	for(j=0;j<512;j++)
			printf("%d",read[i][j]);
		printf("\n");
	}
	*/

	return 0;
}
