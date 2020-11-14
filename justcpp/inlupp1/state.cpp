#include "state.h"


STATE::STATE(char* portName)
{
  this->port = Serial(portName);
  this->admin = Admin();
  this->interface = Interface(this->admin);

}
