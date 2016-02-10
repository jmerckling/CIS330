 #include "game.hpp"
 #include <iostream>

 int main()
 {
     int row, col, steps;
     std::cout<<"Enter grid size (int <space> int):";
     std::cin>>row >> col;
     std::cout<<"Enter the number of steps (int):";
     std::cin>>steps;

    game myGame;
    myGame.gameOfLivestock(row, col, steps);

     return 0;
 }

