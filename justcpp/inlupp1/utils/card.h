#include <ctime>
#include <string.h>

#define STRLEN 40

class Card
{
    public:
      Card(char* new_id);
      void get_id(char* str);
      bool get_access();
      std::time_t get_date();
      void set_access(bool access);
    private:
      char ID[STRLEN];
      bool access;
      std::time_t date_added;

};
