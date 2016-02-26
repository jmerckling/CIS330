#include "SimpleString.hpp"

//Include any other header files as necessary


//Define and implement the SimpleString class methods in this file…

//The 2 constructors are defined for you:

SimpleString::SimpleString() {
    this->input = "Default value";
}

SimpleString::SimpleString(std::string s) {
    this->input = s;
}

//TODO: Define the getter/setter and operator overloading methods…
SimpleString& SimpleString::operator=(const SimpleString& myString){
	myString = this;
	return myString;
}

SimpleString SimpleString::operator+(const SimpleString& myString){
	myString = this;
	myString.append(myString);
	return myString;
}
SimpleString& SimpleString::operator++(){
//	SimpleString.push_back('*');
	this->data = this.push_back('*');
	return *this;
}
SimpleString& SimpleString::operator--(){
	this->data = this.pop_back();
	return this*;
}
