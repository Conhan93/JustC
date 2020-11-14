#ifndef STATE_INCLUDED
#define STATE_INCLUDED

#include <vector>
#include "utils\card.h"
#include "utils\serial.h"
#include "interface.h"
#include "admin.h"


class STATE
{
    public:
      // list of cards
      std::vector<Card> card_list;

      // objects
      Serial port;
      Admin admin;
      Interface interface;

      // constructor
      STATE(char* portName);    
};

#endif
