#include<stdio.c>
#include<math.h>

int num_array[4][4] = {
	1,2,3,4,
	4,5,6,7,
	7,8,9,1,
	1,2,3,4
	};

int main(void){
	int r = 4;
	int c = 4;
	int product, max_product = 0;

	int i, j;

	//Checking accross the rows
	for(i = 0; i < r; i++){
		for(j = 0; j < c -1; j++){
			product = num_array[i][j] * num_array[i][j + 1];
			if(product > max_product){
				max_product = product;
			}
		}
	}

	//Checking accross the coloumns
	for(i = 0; i < c; i++){
		for(j = 0; j < r - 1; j++){
			product = num_array[j][i] * num_array[j + 1][i];
			if(product > max_product){
				max_product = product;
			}
		}
	}

	//Checking accross the diagonals
	for( i = 0; i < r - 1; i++){
		product = num_array[i][i] * num_array[i+1][i+1];
		if(product > max_product){
			max_product = product;
		}
	}

	for(i = 0; i < r - 1; i++){
		product = num_array[i][c - 1 -i] * num_array[i + 1][c - 2 - i];
		if(product > max_product){
			max_product = product;
		}
	}
	
	printf("max --> %d", max_product);
	return 0;
}

	



