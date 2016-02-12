#include <iostream>

using namespace std;

class SimpleString
{
    private:
	char* str;
	int length;
    public:
        SimpleString(); // default constructor declared
	SimpleString(char* str, int length); // non default
};

SimpleString::SimpleString():length(0), str(nullptr)
{
    cout<<"default constructor used"<<endl;
}

SimpleString::SimpleString(char* myString, int myLength):
          str(myString),
          length(myLength)
        {
          cout<<"non-default constructor called"<<endl;
	}

int main()
{
	SimpleString simple;
	SimpleString mySimple = new SimpleString(nullptr, 5);
}//end of main
