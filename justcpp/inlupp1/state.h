#include <vector>
#include "utils\card.h"
#include "utils\serial.h"

class STATE
{
    private:
      std::vector<Card> card_list;
      Serial port;
};
