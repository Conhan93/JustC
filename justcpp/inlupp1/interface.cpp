#include <iostream>
#include "utils\readinput.h"



int main()
{
  char input[50];

  auto scanner = ReadInput();

  scanner.readline(input,50);

  std::cout << input << '\n';
}
