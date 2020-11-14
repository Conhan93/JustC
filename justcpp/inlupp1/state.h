#include <vector>
#include "utils\card.h"
#include "utils\serial.h"

class STATE
{
    public:
      STATE(char* portName)
      {
        this->port = Serial(portName);
      }
    private:
      std::vector<Card> card_list;
      Serial port;
};
