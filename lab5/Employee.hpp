#include <cstdio>
#include <cstdlib>
#include <iostream>
 
using namespace std;
 
class Employee
{
public:
  Employee(string firstName, string lastName, int age);
  void setFirstName( string );
  string getFirstName();
  void setLastName( string );
  string getLastName();
  void setAge( int );
  int getAge();
  void printEmployee();
 
private:
  string firstName;
  string lastName;
  int age;
};
