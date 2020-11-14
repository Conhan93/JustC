#ifndef READ_INPUT_INCLUDED
#define READ_INPUT_INCLUDED
#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cfloat>
#include <ctype.h>

class ReadInput
{
    public:
      bool readline(char* buffer, size_t buffersize);
      bool readint(int* value, int base = 10);
      bool readfloat(float* value);
      bool readchar(char* character);
};


#endif
