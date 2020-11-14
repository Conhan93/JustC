#ifndef ADMIN_INCLUDED
#define ADMIN_INCLUDED

#include "state.h"

class Admin
{
    public:
      Admin();
      bool valid_id(char* new_id);
      void format_date_string(time_t date_added, char* buffer, int buffersize);
      Card* get_card(std::vector<Card>&, std::vector<Card>::size_type, char* search_term);
      void add_card(std::vector<Card>& card_list, char* new_card_id);

};
#endif
