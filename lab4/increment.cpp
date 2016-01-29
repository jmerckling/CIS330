#include <iostream>

void increment1(int x, int y){
	x++;
	y++;
}

void increment2(int &x, int &y){
        x++;
        y++;
}

void increment3(int *x, int *y){
        x++;
        y++;
}

int main(){
	void increment1(int x, int y);
	void increment2(int &x, int &y);
	void increment3(int *x, int *y);
	int x = 0;
	int y = 0;
	
	increment1(x, y);
	std::cout << "\nthe result is: " << x, y;

        increment2(x, y);
        std::cout << "\nthe result is: " << x, y;

//        increment3(x, y);
  //      std::cout << "\nthe result is: " << x, y;

}
