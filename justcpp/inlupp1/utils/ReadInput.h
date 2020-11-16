#ifndef READ_INPUT_INCLUDED
#define READ_INPUT_INCLUDED
#include <string>
#include <iostream>

class ReadInput
{
    public:
      bool readline(char* buffer, int buffersize);
      bool readint(int* value, int base = 10);
      bool readfloat(float* value);
      bool readchar(char* character);
      bool readstring(std::string& input_string,const int size);
};


#endif
