
#include "engine.h"
#include <vector>
#include <ctime>

class Card;

void Engine::add_card(STATE* SYSTEM_STATE, std::string new_ID)
{
    SYSTEM_STATE->card_list.push_back(Card(new_ID));
}
bool Engine::change_access(Card *card, std::string sel)
{
  if(sel == "true")
  {
      card->set_access(true);
      return true;
  }
  else if(sel == "false")
  {
      card->set_access(false);
      return true;
  }
  // unable to set access
  return false;
}
Card* Engine::get_card(STATE *SYSTEM_STATE, std::string search_id)
{

    for(Card& card: SYSTEM_STATE->card_list)
    {
      // return card with matching ID
      if(search_id == card.get_ID()) return &card;
    }
    // return NULL if no card found
    return NULL;
}
void Engine::format_card_time(Card *card, std::string& return_string)
{
    char buffer[40];

    strftime(buffer,40,"%Y-%m-%d",localtime(card->get_time()));

    return_string = buffer;

}
