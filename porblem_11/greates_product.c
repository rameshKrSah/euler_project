#include <stdio.h>

int main(void){
	
	FILE *myFile;
	myFile = fopen("data.txt", "r");
	
	int i, j = 0;
	int num_array[20][20];
	int no_of_rows = 20, no_of_cols = 20;
	
	//reading the data file and storing the data in 20*20 array
	while(!feof(myFile)){
		for(i = 0; i < 20; i++){
			fscanf(myFile, "%d", &num_array[j][i]);
		}
		j++;
	}
	
	//displaying the read datas
	for(i = 0; i < 20; i++){
		for(j = 0; j < 20; j++){
			printf("%d\t", num_array[i][j]);
		}
		printf("\n");
	}
	
	//closing the opened file
	fclose(myFile);
	
	//finding the greatest product
	int product, max_product = 0;
	
	for(i = 0; i < no_of_rows; i++){
		for(j = 0;  j < no_of_cols; j++){
			if( j < no_of_cols - 3){
				//Going Right and Left
				product = num_array[i][j] * num_array[i][j + 1] * num_array[i][j + 2] * num_array[i][j + 3];
				if(product > max_product){
					max_product = product;
				}
			}
			
			if( i < no_of_rows - 3){
				//Going through Down and up
				product = num_array[i][j] * num_array[i + 1][j] * num_array[i + 2][j] * num_array[i + 3][j];
				if(product > max_product){
					max_product = product;
				}
				
				if(j < no_of_cols - 3){
					product = num_array[i][j] * num_array[i+1][j+1] * num_array[i+2][j+2] * num_array[i+3][j+3];
					if(product > max_product){
						max_product = product;
					}
				}
				
				if(j > 3){
					product = num_array[i][j] * num_array[i+1][j-1] * num_array[i+2][j-2] * num_array[i+3][j-3];
					if(product > max_product){
						max_product = product;
					}	
				}
			}	
		}
	}
	printf("max_product --> %d", max_product);
	return 0;
}

//ref: http://www.geekality.net/2009/10/03/project-euler-problem-11/
