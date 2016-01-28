#include <stdio.h>
#include <string.h>

#include "directory.h"
 /*
typedef struct Directory {
  	char firstName[25];
	char lastName[25];
  	char phoneNumber[20];
	int ID;	
} person;
*/
void add(int *person_ctr, person *struct_name, int counter){
	(*person_ctr++);
	counter++;
	printf("\nEnter a first name:");
	scanf("%s", struct_name[*person_ctr - 1].firstName);
        printf("\nEnter a last name:");
        scanf("%s", struct_name[*person_ctr - 1].lastName);
	printf("\nEnter a phone number:");
	scanf("%s", struct_name[*person_ctr - 1].phoneNumber);
	struct_name[counter].ID = counter;
}//end add
void removeEnt(int *person_ctr, person *struct_name){
	int i;
	int num;
	printf("\nWhich entry would you like to delete(enter the ID#):");
	scanf("%d", &num);
	for(i = 0; i < *person_ctr; i++){
		if(num == struct_name[i].ID){
			//struct_name[i].name = {NULL};
			//struct_name[i].phoneNumber = '0';
			struct_name[i].ID = -1;
		}
		else{
		printf("\nEntry not found!");
		}
	}
}// end delete
void display(int *person_ctr, person *struct_name){
	int i;
	printf("\ncurrent dierctory:");
	for(i = 0; i < *person_ctr + 1; i++){
		int linecount = 1;
		if(struct_name[i].ID != -1){
		printf("\n%d. %s %s, %s, ID:%d", linecount, struct_name[i].firstName, struct_name[i].lastName, struct_name[i].phoneNumber, struct_name[i].ID);
		linecount++;
		}
	}
}//end display
