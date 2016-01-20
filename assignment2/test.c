//Includes main to test functions
#include <stdio.h>
#include <stdlib.h>

#include "triangle.h"

int main(){
	//Problem 1
	 printf("Problem 1 (a triangle of height 5):\n"); /* Fixed-size square */
 	 print5Triangle();
	
	//Problem 2
	int **triangle;
	printf("\nProblem 2\n");
	int height;
	
	printf("Please enter the height of the triangle [1-5]:");
	scanf("%d", &height);
	while(height < 1 || height > 5){
		printf("Please enter the height of the triangle [1-5]:");
		scanf("%d", &height);
	}
	
	allocateNumberTriangle( (const int) height, &triangle );
 	initializeNumberTriangle( (const int) height, triangle );
 	printNumberTriangle( (const int) height, triangle );

 	 // Free memory allocated earlier
 	 deallocateNumberTriangle( (const int) height, triangle );

  return 0;
}//end main
