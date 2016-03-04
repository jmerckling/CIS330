#include <iostream>
#include <ctime>
#include <numeric>
#include <fstream>

using namespace std;

//prototype
void fillFunc(int*);
void printFunc(int*);

int main()
{
int random[10]; //0-24 is 25 remember array indeices
srand((unsigned)time(NULL));
fillFunc(random);
//fork
if (fork() == 0) {
 ofstream outFile;
 outFile.open ("out.txt");
 int childAdd = accumulate(begin(random), 4, 0, plus<int>());
 outFile <<"\nSum of 0-4 is; " << childAdd <<endl;
} else {
 outFile.close();
}

printFunc(random);
int total = accumulate(begin(random), end(random), 0, plus<int>());
cout << "\nThe total is: " << total << endl;
return 0;
}

void fillFunc(int* arr)
{
        for (int i = 0; i < 10; i++)
        {
                    arr[i] = 1+ rand() % 10;
         }

}
void printFunc(int* arr)
{
         for (int i = 0; i < 10; i++)
          {
                    cout << arr[i] << " ";
         }
}
