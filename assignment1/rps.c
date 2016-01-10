//Jordan Merckling
//Assignment 1
/* File: rps.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* getUserChoice() {
    /* Prompt the user "Enter rock, paper, or scissors: " and return
       the string they enter */
       char* choice;
       printf("Enter rock, paper, or scissors: ");
       scanf("%s",choice);
       return choice;
}
char* getComputerChoice() {
    srand (time(NULL));
    /* get a pseudo-random integer between 0 and 2 (inclusive) */
    int randChoice = rand() % 3;

    /* If randChoice is 0, return "rock"; if randChoice is 1,
     return "paper", and if randChoice is 2, return "scissors". */
     if (randChoice == 0)
        return "rock";
     if (randChoice == 1)
        return "paper";
     if (randChoice == 2)
        return "scissors";

}
char* compare(char* choice1, char* choice2)
{
    /* Implement the logic of the game here. If choice1 and choice2
     are equal, the result should be "This game is a tie."*/
    if (strcmp(choice1,choice2) == 0)
    {
        return "This game is a tie.";
    }

    else if (strcmp(choice1,"rock") == 0)
        {
            if (strcmp(choice2, "scissors") == 0)
                {
                    return "rock wins";
                }
                    else
                        {
                            return "paper wins";
                        }
        }
else if (strcmp(choice1,"paper") == 0)
{
    if (strcmp(choice2,"rock") == 0)
        {
            return "paper wins";
        }
    else
        {
            return "scissors wins";
        }
}
else if (strcmp(choice1,"scissors") == 0)
    {
            if (strcmp(choice2,"paper") == 0)
                {
                    return "scissors wins";
                }
        else
        {
            return "rock wins";
        }
    }
else
    {
        return "Invalid user choice, you must enter rock, paper, or scissors.";
    }
}
int main(int argc, char *argv[])
{
   char *userChoice = NULL, *computerChoice = NULL, *outcome = NULL;

    userChoice = getUserChoice();
    computerChoice = getComputerChoice();

    outcome = compare(userChoice, computerChoice);

    printf("You picked %s.\n", userChoice);
    printf("Computer picked %s.\n", computerChoice);
    printf("%s\n", outcome);

    return 0;
}

