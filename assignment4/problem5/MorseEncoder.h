#ifndef MORSEENCODER_H
#define MORSEENCODER_H

#include <string>

class MorseEncoder{
     public :
            //function to receive a string to convert
            std::string encode(std::string myWord);

            //Function that will have the characters as their repective morse representation
            std::string toMorse(char letter);
};
 
#endif
