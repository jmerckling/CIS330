#include "Battleship.h"

void setGame(struct board *b1, struct board *b2)
{
    //5 total ships
    int shipCount = 5;
    //10 rows and columns
    int sizeOfBoard = 10;

    int *b1shipHP = (int *) malloc((shipCount + 1) * sizeof(int));
    int *b2shipHP = (int *) malloc((shipCount + 1) * sizeof(int));

    b1shipHP[0] = 0;
    b1shipHP[1] = 2;
    b1shipHP[2] = 3;
    b1shipHP[3] = 3;
    b1shipHP[4] = 4;
    b1shipHP[5] = 5;

    b2shipHP[0] = 0;
    b2shipHP[1] = 2;
    b2shipHP[2] = 3;
    b2shipHP[3] = 3;
    b2shipHP[4] = 4;
    b2shipHP[5] = 5;

    b1->shipCount = shipCount;
    b1->sunkShips = 0;
    b1->shipHP = b1shipHP;
    b1->boardSize = sizeOfBoard;
    b1->map = NULL;

    b2->shipCount = shipCount;
    b2->sunkShips = 0;
    b2->shipHP = b2shipHP;
    b2->boardSize = sizeOfBoard;
    b2->map = NULL;

    //new files can be given
    char fName1[] = "board1.txt";
    char fName2[] = "board2.txt";

    //load in random board for each player
    //randMap(b1);
    //randMap(b2);

    //make boards for each player
    loadBoard(fName1, b1);
    loadBoard(fName2, b2);
}

//read from file to make a player board
int loadBoard(char *pFile, struct board *pBoard)
{
    int result = 0;

    const int MAX_FILE_SIZE = pBoard->boardSize * (pBoard->boardSize + 1);
    FILE *fp = fopen(pFile, "r");

    if(fp == NULL)
    {
        printf("File not found!", pFile);
        result = 1;
    }
    else
    {

        pBoard->map = (char *) malloc(MAX_FILE_SIZE * sizeof(char));
        memset(pBoard->map, '0', MAX_FILE_SIZE);
        if(pBoard->map == NULL)
        {
            printf("Memory Overflow!");
            result = 2;
        }
        else
        {
            fread(pBoard->map, MAX_FILE_SIZE, 1, fp);
        }
    }

    fclose(fp);//close file reader
    return result;
}

//function to create a random map
void randMap(struct board* b)
{
    //initialize values
    int mapSize = b->boardSize * (b->boardSize + 1);
    int placedShips[b->shipCount];
    for(int i = 0; i < b->shipCount; ++i)
    {
        placedShips[i] = 0;
    }

    //map begins with all water
    b->map = (char *) malloc(mapSize * sizeof(char));
    memset(b->map, '0', mapSize);

    //place one ship at a time
    int curShip = -1;
    int direction = -1; //random if ship is horizontal or vertical
    int curCol = -1;
    int curRow = -1;
    int shipOverlap = 0; //make sure ships do not get placed in the same square
    for(int i = 0; i < b->shipCount; ++i)
    {
        //pick a random ship to be placed
        curShip = rand() % b->shipCount;
        while(placedShips[curShip] != 0)
        {
            curShip = rand() % b->shipCount;
        }
        placedShips[curShip] = 1;
        //random direction, 0 for horizontal, 1 for vertical
        direction = rand() % 2;
        //place from random spot of the ship
        //make sure no overlapping
        do
        {
            shipOverlap = 0; //set back to 0 after each placement
            if(direction == HORIZONTAL)
            {
                curCol = rand() % (b->boardSize - b->shipHP[curShip + 1]);
                curRow = rand() % b->boardSize;
                for(int j = 0; j < b->shipHP[curShip + 1]; j++)
                {
                    //if ships are being placed in not water (overlapping)
                    if(*(b->map + (curRow * (b->boardSize + 1)) + (curCol + j)) != '0')
                    {
                        //ships are overlapping
                        shipOverlap = 1;
                    }
                }
            }
            else
            {
                curCol = rand() % b->boardSize;
                curRow = rand() % (b->boardSize - b->shipHP[curShip + 1]);
                for(int j = 0; j < b->shipHP[curShip + 1]; j++)
                {
                    if(*(b->map + ((curRow + j) * (b->boardSize + 1)) + (curCol)) != '0')
                    {
                        shipOverlap = 1;
                    }
                }
            }
        }
        //When ships have overlap, change the ships placement by moving vertically or horizontally depending on direction
        while(shipOverlap == 1);
        for(int j = 0; j < b->shipHP[curShip + 1]; j++)
        {
            *(b->map + ((curRow + j * direction) * (b->boardSize + 1)) + (curCol + j * (1 - direction))) = '0' + (curShip + 1);
        }
    }
}

//print the game board with coordinates
void printBoard(struct board *b, int viewAll)
{
    printf("  ABCDEFGHIJ\n");
    for(int i = 0; i < b->boardSize; ++i)
    {
        char *curStr = (b->map) + (i * (b->boardSize + 1));
        printf("%d ", i);
        for(int j = 0; j < (b->boardSize); ++j)
        {
            //only show player info they know from shots they have taken
            if(viewAll || *(curStr + j) == '-' || *(curStr + j) == 'X')
            {
                printf("%c", *(curStr + j));
            }
            else
            {
                printf("?");
            }
        }
        printf("\n");
    }
}

//function to receive coords and check if it will hit something
int shoot(struct board* b, int col, int row)
{
    int result = 0;

    //begin at begining of array and jump to row and column based on coords
    char *point = ((b->map) + ((b->boardSize + 1) * row) + (col));

    //update opponents board
    if(*point > '0' && *point != 'X')
    {
        //find ship type from number being hit
        int arrayOffset = (int)((*point) - '0');

        //get ship being shot
        int *curShip = ((b->shipHP) + arrayOffset);

        //if sunken print what ship was taken down
        if(*curShip == 1)
        {
            printf("You sunk a ship or boat #%c\n", *point);
            b->sunkShips++;
        }

        //reduce ship hp
        (*curShip)--;

        //X to mark a hit
        *point = 'X';

        result = 1;
    }
    else
    {
        // - to mark a miss
        *point = '-';
    }

    return result;
}

//function for what happens during a turn
void playerTurn(int player, struct board *myBoard, struct board *enemyBoard)
{
    //initial values
    char col = 'A';
    int row = 0;
    int hit = 0;
    int shotCoords = 0;

    printf("Player %d, please press enter to begin your turn!", player);
    getchar();

    printf("It's Player %d's turn, this is the intel you currently have on enemy ship positions:\n", player);
    printBoard(enemyBoard, 0);
    printf("Here are your ships current locations and condition!\n");
    printBoard(myBoard, 1);
    printf("Enter coordinates to be fired upon in column(A - J), row(0 - %d) format. (for example C4 or J2): ", myBoard -> boardSize);
    //get coords to shoot
    shotCoords = scanf("%c%d", &col, &row);
    emptyBuffer();// clear input buffer
    col -= 'A'; // reset column

    //input validation
    while(shotCoords !=2 || (col < 0 || col > enemyBoard->boardSize - 1) || (row < 0 || row > enemyBoard->boardSize - 1))
    {
        printf("Invalid Coordinates!\n");
        printf("Enter coordinates to be fired upon in column(A - J), row(0 - %d) format.(for example C4 or J2): ", myBoard -> boardSize);
        shotCoords = scanf("%c%d", &col, &row);
        emptyBuffer();
        col -= 'A';
    }

    //reiterate where shots are being fired
    printf("Firing Upon: %c%d\n", (col + 'A'), row);
    hit = shoot(enemyBoard, col, row);

    //hit a ship
    if(hit > 0)
    {
        printf("You hit an enemy ship at coordinates %c%d!\n", col + 'A', row);
        printf("Marking up a hit marker on the radar...\n");
    }
    //hit water
    else
    {
        printf("Your shot hit nothing but water at coordinates %c%d!\n", col + 'A', row);
        printf("Flagging the area as an empty zone on the radar...\n");
    }

    //between turns transition, mainly for when playing another human to avoid cheating
    printf("Player %d, please press enter to allow the enemy to fire.", player);
    getchar();
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
//function for AI player
void aiPlayer(struct board *b)
{
    int col = 0;
    int row = 0;

    //fire in random locations, do not hit same spot twice.
    char point = 'X';
    do
    {
        col = rand() % b->boardSize;
        row = rand() % b->boardSize;
        point = *(b->map + (row * (b->boardSize + 1)) + col);
    }
    while(point == 'X' || point == '-');

    shoot(b, col, row);
}

//check if a player has lost all of their ships
int checkLoss(struct board *b)
{
    return (b->sunkShips >= b->shipCount);
}

//function to clear input
void emptyBuffer()
{
    char c = '\n';
    while(c = getchar() != '\n' && c != EOF)
    {
        //do nothing
    }
}

