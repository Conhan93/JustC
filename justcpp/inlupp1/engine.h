#ifndef ENGINE_INCLUDED
#define ENGINE_INCLUDED
#include "utils\state.h"

class Engine
{
  public:
    // static methods
    static void add_card(STATE* SYSTEM_STATE, std::string new_ID); // add card to list
    static bool change_access(Card *card, std::string sel); // set new access
    static Card* get_card(STATE *SYSTEM_STATE, std::string search_id); // find card
    static void format_card_time(Card *card, std::string& return_string);
};
#endif
