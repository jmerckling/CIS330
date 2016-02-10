//header file for game of live stock
class game
{
public:
    //method to make a 2-d array and initialize values
    char** makeArray(int row, int col);

    //method to run an iteration of the steps, updating the previous array
    char** runStep(char** board, int row, int col);

    //method to print current 2-d array
    void printStep(char** board, int row, int col);

    //method to delete allocated array
    void deleteArray(char** board, int row);

    //method to run the program the amount of times the user wants, and the size of the array they want
    void gameOfLivestock(int row, int col, int steps);
};

