#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define ROW 3
#define COL 4

bool arrayEqual(int a[ROW][COL], int b[ROW][COL], int m, int n)
{
    	int i = 0;
	int j = 0;
	for(i = 0;i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
		}
		if(a[i][j] != b[i][j])
		return false;
	} 
	return true;
}


int main(int argc, const char * argv[])
{
bool x;
int** a2;
int** b2;


    int a[ROW][COL] = {
        {0, 1, 2, 3} ,
        {4, 5, 6, 7} ,
        {8, 9, 10, 11}
    };

    int b[ROW][COL] = {
        {0, 1, 2, 3} ,
        {4, -1, 6, 7} ,
        {8, 9, 10, 11}   
    };
x = arrayEqual(a, b, ROW, COL);


   printf ("result  %d/n", x);

    return 0;
}
