#include <iostream>
#include "readinput.h"





int main()
{
    char input[50];
    ReadInput scanner = ReadInput();

    scanner.readline(input,50);

    std::cout << input << '\n';
}
