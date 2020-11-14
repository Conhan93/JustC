#include <ctime>

class Card
{
    private:
      char ID[STRLEN];
      bool access;
      std::time_t date_added;
};
