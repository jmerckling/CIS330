#ifndef DIRECTORY_H_
#define DIRECTORY_H_

typedef struct Directory {
        char firstName[25];
        char lastName[25];
        char phoneNumber[20];
        int ID;
} person;

/* Add a contact */
void add(int *person_ctr, person *struct_name, int counter);

/*Remove a contect */
void removeEnt(int *person_ctr, person *struct_name);

/*display directory*/
void display(int *person_ctr, person *struct_name);

#endif /* DIRECTORY_H_ */
