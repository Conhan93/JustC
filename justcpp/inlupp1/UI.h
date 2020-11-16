#ifndef UI_INCLUDED
#define UI_INCLUDED
class STATE;
class Card;

#include "utils\ReadInput.h"



class UI
{
    public:
      // methods
      UI(); // Interface initialization
      void print_menu(); // prints menu options
      void menu(STATE* SYSTEM_STATE); // menu loop
      void display_cards(STATE* SYSTEM_STATE); // displays cards in card list
      void card_menu(STATE* SYSTEM_STATE); // handles card creation
      void print_card(Card *card); // prints card for display list method
      void change_access(Card *card);
      void fake_scan(STATE *SYSTEM_STATE);

      // variables/objects
      class ReadInput Scanner;

};
#endif
