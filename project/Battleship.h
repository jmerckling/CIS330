#ifndef BATTLESHIP_H_
#define BATTLESHIP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define HORIZONTAL 0
#define VERTICAL 1

struct board
{
    int shipCount;
    int sunkShips;
    int boardSize;
    char *map;
    //Hit point value of ships, at 0 ship is sunk
    int *shipHP;
};

void setGame(struct board *b1, struct board *b2);
int loadBoard(char *p1File, struct board *p1Board);
void randMap(struct board* b);
void printBoard(struct board *b, int viewAll);
int shoot(struct board* b, int col, int row);
void playerTurn(int player, struct board *myBoard, struct board *enemyBoard);
void aiPlayer(struct board *b);
int checkLoss(struct board *b);
void emptyBuffer();

#endif
