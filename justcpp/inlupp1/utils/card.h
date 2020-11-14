#include <ctime>

#define STRLEN 40

class Card
{
    private:
      char ID[STRLEN];
      bool access;
      std::time_t date_added;
    public:
      Card(char* new_id);
      void get_id(char* str);
      bool get_access();
      std::time_t get_date();
      void set_access(bool access);
};
