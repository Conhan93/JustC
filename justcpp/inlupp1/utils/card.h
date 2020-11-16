

#include <ctime>
#include <string>

class Card
{
    private:
      // Card values
      std::string ID;
      bool access;
      time_t date_added;
    public:
      // Card methods
      Card(std::string ID);
      bool get_access();
      void set_access(bool new_access);
      time_t* get_time();
      std::string& get_ID();

};
