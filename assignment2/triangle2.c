//Implementation for triangle2 functions
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Allocate a triangle of height "height" (a 2-D array of int) */
void allocateNumberTriangle(const int height, int ***triangle){
	int col = (height * 2) - 1;
	*triangle = (int**)malloc(height * sizeof(int*));
		for(int i = 0; i < height; i++){
		(*triangle)[i] = (int*)malloc(col * sizeof(int));
		}
}//end of allocate func

/* Initialize the 2-D triangle array */
void initializeNumberTriangle(const int height, int **triangle){
	        int counter, row;
        for(row = 0; row < height; row++){
		for(counter = 0; counter < (((row + 1) * 2) - 1); counter++){
			triangle[row][counter] = counter;
		}
	}


}//end of initialize func
/* Print a formatted triangle */
void printNumberTriangle(const int height, int **triangle){

	int row, colSpace, num;
        for(row = 0; row < height; row++){

                for(colSpace = (height - row);colSpace >= 1; colSpace--){
                        printf("  ");
                }

                for(num = 0; num <(((row + 1) * 2) - 1); num++){
                printf("%d ", triangle[row][num]);
                }
                printf("\n");
        }

}//end of print func

/* Free the memory for the 2-D triangle array */
void deallocateNumberTriangle(const int height, int ***triangle){
	for(int i = 0; i < height; i++){
		free((*triangle)[i]);
	}
	free(*triangle);
}//end of deallocate
