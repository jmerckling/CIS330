#include "Battleship.h"
int main(int argc, char *argv[])
{
    srand(time(NULL));

    struct board b1;
    struct board b2;
    setGame(&b1, &b2);

    printf("Time to play Battleship!\n_______________________________\n_______________________________\n");
    printf("\n");

    printf("player 1 will be using this board\n");
    printBoard(&b1, 1);
    printf("player 2 will be using this board\n");
    printBoard(&b2, 1);
    printf("Let's begin!\n");

    //player one set as user
    int curPlayer = 1;
    while(checkLoss(&b1) == 0 && checkLoss(&b2) == 0)
    {
        //alternate turns, shoot then next player
        if(curPlayer == 1)
        {
            playerTurn(curPlayer, &b1, &b2);
            curPlayer++;
        }
        else
        {
            //playerTurn(curPlayer, &b2, &b1);
            aiPlayer(&b1);
            curPlayer--;
        }
    }
    if(checkLoss(&b1) != 0)
    {
        printf("Player 2 wins! Sorry player 1");
    }
    else
    {
        printf("Player 1 wins! Sorry player 2");
    }

    return 0;
}

