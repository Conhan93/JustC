#ifndef STATE_INCLUDED
#define STATE_INCLUDED

#include <vector>
#include "utils\card.h"
#include "utils\serial.h"
#include "admin.h"

class STATE
{
    public:
      STATE(char* portName)
      {
        this->port = Serial(portName);
        this->admin = Admin();
      }
      std::vector<Card> card_list;
      Serial port;
      Admin admin;

};

#endif
