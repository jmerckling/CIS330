/*Source file to implement functions*/
#include <stdio.h>

void print5Triangle(){
	int row, colSpace, num;
	static int A[5][9] =  {
		{0} ,
		{0, 1, 2} ,
		{0, 1, 2, 3, 4} ,
		{0, 1, 2, 3, 4, 5, 6} ,
		{0, 1, 2, 3, 4, 5, 6, 7, 8}
	};
	for(row = 0; row < 5; row++){
		
		for(colSpace = (5 - row);colSpace >= 1; colSpace--){
			printf("  ");
		}

		for(num = 0; num <(((row + 1) * 2) - 1); num++){
		printf("%d ", A[row][num]);
		}
		printf("\n");
	}

}// end of function
