#ifndef LIGHTENCODER_H
#define LIGHTENCODER_H

#include "MorseEncoder.h"

class LightEncoder: public MorseEncoder{
  public:
      // function to turn morse string to light output
      void MorseEncoder::LightEncoder(std::string inMorse);
};

#endif

