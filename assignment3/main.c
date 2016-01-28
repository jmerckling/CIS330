#include <stdio.h>
#include <stdlib.h>

#include "directory.h"

int main(){
	person contact[50];
	int counter = 0;
	int person_ctr = 0;
	person* pcontacts;
	pcontacts = (person*) calloc(0, sizeof(person));
	int option = 0;

	while(option != 4){
		printf("\n\t\t\tDirectory Menu");
     		printf("\n\n\t(1)\tAdd Entry");
     		printf("\n\t(2)\tDelete Entry");
     		printf("\n\t(3)\tDisplay Current Entries");
     		printf("\n\t(4)\tExit Directory");
     		printf("\n\nChoose an option:");
     		scanf("%d", &option);
		while(option > 4 || option < 1){//input validation loop
			printf("\nEnter a valid option (1-4):");
			scanf("%d", &option);
		}
		if(option == 1){//add contact
			pcontacts = realloc(pcontacts, person_ctr * sizeof(person));
			add(&person_ctr, contact, counter);
		}
		if(option == 2){//remove contact
			removeEnt(&person_ctr, contact);
		}
		if(option == 3){//display entries
			display(&person_ctr, contact);
		}
		if(option == 4){//exit program
			//program will exit
		}
	}//end of while

	return 0;
}//end of main
