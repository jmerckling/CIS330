#include "MorseEncoder.h"
#include <iostream>


//toMorse implementation
std::string MorseEncoder::toMorse(char letter){
  std::string text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //UPPER case alphabet to compare
    std::string morse[] = {".- ","-... ","-.-. ","-.. ", ". ", "..-. ", "--. ",
                      ".... ", ".. ", ".--- ", "-.- ", ".-.. ", "-- ",
                      "-. ", "--- ", ".--. ", "--.- ", ".-. ", "... ", "- ",
                      "..- ", "...- ", ".-- ", "-..- ", "-.-- ", "--.. "}; //morse alphebet to return
      int index = text.find(letter);
        if(index!=-1)
            return morse[index];
         else
            return " ";
}

std::string MorseEncoder::encode(std::string myWord){
  std::string morse = "";   //string to return
  for(int i = 0; i < myWord.length(); i++){
    morse += toMorse(myWord[i]);  // updates morse
  }
  return morse;
}

