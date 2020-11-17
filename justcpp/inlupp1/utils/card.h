

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
      Card(std::string ID, bool access, time_t date);
      bool get_access();
      void set_access(bool new_access);
      time_t* get_time();
      void set_time(time_t date_added);
      std::string& get_ID();

};
