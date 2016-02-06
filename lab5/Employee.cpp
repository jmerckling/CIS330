#include "Employee.h"
using namespace std;
 
//initialization
Employee::Employee(string initFirstName, string initLastName, int initSalary)
{
  setFirstName(firstName);
  setLastName(lastName);
  setAge(age);
}
 
//function for set first name
void Employee::setFirstName(string firstName)
{
  myFirstName = firstName;
}
//function for get first name
string Employee::getFirstName()
{
  return myFirstName;
}
//function for set last name
void Employee::setLastName(string lastName)
{
  myLastName = lastName;
}
//function for get last name
string Employee::getLastName()
{
  return myLastName;
}
//function for set age
void Employee::setAge(int age)
{
  if (age < 0)
  {
     cout << "Age cannot be negative, age will be set to 0 for now." << endl;
     age = 0;
   }
    else
   {
     myAge = age;
   }
}
//function for get age
int Employee::getAge()
{
  return myAge;
}
//function for print employee
void Employee::printEmployee()
{
  cout << "Curent Employee:" << endl;

}
