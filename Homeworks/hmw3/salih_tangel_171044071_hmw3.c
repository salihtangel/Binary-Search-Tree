#include <math.h>
#include <stdio.h>

#define max 100
#define max2 1000
int find_length(char * s1){
	int i=0;
	while(*s1 != '\0')
	{
		i++;
		s1++;
	}
	return i;
}
int main() {
	double numbers[max];	/*for values.txt*/
	char polynomial[max2];	/*for polynomial.txt*/
	double define_record[max];	/*for evaliations.txt*/
	double d1, d3;  // to record pow
	int i=0, j=0,k=0;
	double x;  /* it is x */
	double result = 0;	/*for record results*/
	FILE *fp;
	int length_of_polynomial=0;
	int flag_for_pow=0;
	int flag_for_first_time=0;


	/*reading values.txt*/
	fp = fopen("values.txt", "r");
	if (fp == NULL) {
		printf("it could no opened\n");
		return 0;
	}
	while (!feof(fp)) {
		fscanf(fp, "%lf", &numbers[i]);
		i++;
	}
	fclose(fp);

	/*to find number of value.txt*/
	while(j<i-1){
		j++;
	}

	/* reading polynomial.txt file*/
	fp = fopen("polynomial.txt", "r");
	if (fp == NULL) {
		printf("it could no opened\n");
		return 0;
	}
	while (!feof(fp)) {
		fscanf(fp, "%s", polynomial);
	}
	fclose(fp);


	/*we are finding length of polynomial.txt*/
	length_of_polynomial=find_length(polynomial);
int m =0;
	/*we are adding '(' and ')' characters a copy string*/
	char copy_polynomial[max2];
	while(m<length_of_polynomial){
		copy_polynomial[m+1]=polynomial[m];
		m++;
	}
	copy_polynomial[0]='(';
	copy_polynomial[m+1]=copy_polynomial[m+2];
	copy_polynomial[m+1]=')';

	/*Here parsing is staring*/
	// j is for values.txt and k for polynomial.txt
	for (j = 0; j < i-1; j++) {
		for (k = 0; copy_polynomial[k]!='\0'; k++) {
			if(copy_polynomial[k]=='('  &&  copy_polynomial[k+1]!='x'){	/*for first time  i am using '(' which i added  before*/
				k++;
				sscanf(copy_polynomial+k,"%lf",&d1);
				flag_for_first_time=1;
			}
			else if (copy_polynomial[k] == '+' ||  copy_polynomial[k] == '-' || copy_polynomial[k]==')' &&  flag_for_first_time==1) { /*main part results are adding here*/
				if(flag_for_pow ==1 ){
					result += x;
					sscanf(copy_polynomial+k+1,"%lf",&d1);
					flag_for_pow=0;
				}else if(flag_for_pow==0){		/*-5*x and -5* cases*/
					if(copy_polynomial[k-1] == 'x'){
						result+=x*d1;
						sscanf(copy_polynomial+k+1,"%lf",&d1);
					}else {				/*-5 cases*/
						result+=x;
						sscanf(copy_polynomial+k+1,"%lf",&d1);
					}
				}
			}else if (copy_polynomial[k] == 'x') {		/*reading x*/
				x=numbers[j];
				flag_for_first_time =1;
				if( copy_polynomial[k-1] == '('  &&  copy_polynomial[k+1] != '^')	/*reading pow and cases*/
					result+=x;
				else if(copy_polynomial[k-1] == '-' && copy_polynomial[k-2] == '('  &&  copy_polynomial[k+1] != '^')
						result= -1*x;
			} else if (copy_polynomial[k] == '^') {
				flag_for_pow=1;
				sscanf(copy_polynomial + k + 1, "%lf", &d3);
				x = numbers[j];
				// these statements are for -x^2
				if (copy_polynomial[k - 2] == '-' ) {
					x = -1 * pow(x, d3);
				}
				//these statements are for +x^2
				else if (copy_polynomial[k - 2] == '+' || copy_polynomial[k - 2] =='('    &&   copy_polynomial[k+2] == ')') {
					x = pow(x, d3);
				}
				//these statements are for 5*x^2
				else {
					x = (pow(x, d3) * d1);
				}
			}
		}
		// end of for one value on polynomial and writing result on a double array
		define_record[j]=result;
		result = 0;
	}
	fclose(fp);
	//we are writing file for define_record
	fp = fopen("evaluations.txt", "w");
i=0;
	while(i<j){
		fprintf(fp,"%.2lf\n",define_record[i]);
		i++;
	}
	return 1;
}

