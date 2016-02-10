#include "game.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

//method to make a 2-d array and initialize values
char** game::makeArray(int row, int col)
{
    //initialize seed for random
    srand (time(NULL));
    //Variables larger that board user wants for logic on outer squares
    int ROWS, COLS;
    ROWS = row + 2;
    COLS = col + 2;
    char boardTypes[4] = {'S', 'W', 'F', '.'};
    char** board;   //board array
    board = new char*[ROWS]; //set rows

      for (int r = 0; r < ROWS; r++)
      {
            board[r] = new char[COLS];   //set cols

            for (int c = 0; c < COLS; c++)
            {
                // fill with random chars from boardTypes with rand
                board[r][c] = boardTypes[rand() % 4]; // random value from array bTypes between 0-3
            }
      }
      return board;

}//end of makeArray

char** game::runStep(char** board, int row, int col)
{
    int ROWS, COLS;
    ROWS = row + 2;
    COLS = col + 2;
    //set newBoard
    char** newBoard = new char*[ROWS];
    for(int i = 0; i < ROWS; i++)
        newBoard[i] = new char[COLS];

    //count each instance of a species within 8 blocks of chosen blocks
    //then determine change
    for (int r = 1; r < (ROWS - 1); r++)
	{
		for (int c = 1; c < (COLS - 1); c++)
		{
		    //counts for all variables
			int sheep = 0;
			int wolf = 0;
			int farmer = 0;
			int blank = 0;

            for(int rn = (r - 1); rn <= (r + 1); rn++)// run through the 8 squares surrounding (r,c), excluding (r,c)
            {
                for(int cn = (c - 1); cn <= (c + 1); cn++)
                {
                    if(rn != r || cn != c) // to exclude (r,c);
                    { //counts all pieces in squares touching (r,c)
                        if(board[rn][cn] == 'S')
                            sheep++;
                        else if(board[rn][cn] == 'W')
                            wolf++;
                        else if(board[rn][cn] == 'F')
                            farmer++;
                        else
                            blank++;
            // cases for what (r,c) is
            if(board[r][c] == 'S')// possible outcomes when square is a sheep
            {
                if(sheep > 3)           //die from over population
                    newBoard[r][c] = '.';
                else if (wolf >= 1)     //die from predation
                    newBoard[r][c] = '.';
                else                    //square remains a sheep
                    newBoard[r][c] = 'S';
            }
            else if(board[r][c] == 'W')// possible outcomes when square is a wolf
            {
                if(wolf > 3)            //die from overpopulation
                    newBoard[r][c] = '.';
                else if(farmer >= 1)    //die from hunting
                    newBoard[r][c] = '.';
                else                    //square remains wolf
                    newBoard[r][c] = 'W';
            }
            else if(board[r][c] == 'F')// possible outcomes when square is a farmer
                {
                    if (board[r-1][c-1]== '.')
                        {
                            newBoard[r][c] = '.';
                            newBoard[r-1][c-1] = 'F';
                        }
                   else if (board[r-1][c]== '.')
                        {
                            newBoard[r][c] = '.';
                            newBoard[r-1][c] = 'F';
                        }
                   else if (board[r-1][c+1]== '.')
                        {
                            newBoard[r][c] = '.';
                            newBoard[r-1][c+1] = 'F';
                        }
                   else if (board[r][c-1]== '.')
                        {
                            newBoard[r][c] = '.';
                            newBoard[r][c-1] = 'F';
                        }
                   else if (board[r][c+1]== '.')
                        {
                            newBoard[r][c] = '.';
                            newBoard[r][c+1] = 'F';
                        }
                   else if (board[r+1][c-1]== '.')
                        {
                            newBoard[r][c] = '.';
                            newBoard[r+1][c-1] = 'F';
                        }
                   else if (board[r+1][c+1]== '.')
                        {
                            newBoard[r][c] = '.';
                            newBoard[r+1][c+1] = 'F';
                        }
                   else if (board[r+1][c]== '.')
                        {
                            newBoard[r][c] = '.';
                            newBoard[r+1][c] = 'F';
                        }
                    else
                        newBoard[r][c] = 'F';
           }
            else if(board[r][c] == '.')// possible outcomes when square is a empty
            {
                if(sheep == 2)
                    newBoard[r][c] = 'S';
                else if(wolf == 2)
                    newBoard[r][c] = 'W';
                else if(farmer == 2)
                    newBoard[r][c] = 'F';
                else
                    newBoard[r][c] = '.';
            }
            else
                newBoard[r][c] = '.';
		}
	}
}//end of inner loop


		}
	}//end of outter for loop
	return newBoard;
}//end of runStep
void game::printStep(char** board, int row, int col)
{
    int ROWS, COLS;
    ROWS = row + 2;
    COLS = col + 2;
    //loop to print array by row and column
for (int i = 1; i < (ROWS - 1); ++i)
    {
        for (int j = 1; j < (COLS - 1); ++j)
        {
            std::cout << board[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}// end of printStep
void game::deleteArray(char** board, int row)
{
    int ROWS;
    ROWS = row + 2;

    for (int i = 0; i < ROWS; ++i)
        delete [] board[i];
      delete [] board;
}

void game::gameOfLivestock(int row, int col, int steps)
{
    char** newArray = makeArray(row, col);
    char** stepArray = newArray;
    printStep(newArray, row, col);
    std::cout<<std::endl;
    std::cout <<"Step 1:"<< std::endl;
    stepArray = runStep(newArray, row, col);
    printStep(stepArray, row, col);
    for(int i = 2; i <= steps; i++)
    {
        std::cout<<std::endl;
        std::cout<<"Step "<<i<<":"<<std::endl;
        stepArray = runStep(stepArray, row, col);
        printStep(stepArray, row, col);
    }
    deleteArray(newArray, row);
    deleteArray(stepArray, row);
}


