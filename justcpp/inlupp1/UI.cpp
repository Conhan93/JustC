#include "UI.h"
#include "engine.h"
#include <iostream>
#include <cstring>
#include <string>




UI::UI()
{
  // Create scanner object
  this->Scanner = ReadInput();
}
void UI::print_menu()
{
    // print menu options
    std::cout << "1. Add Cards" << '\n'
    << "2. Display Cards" << '\n'
    << "3. Fake Scan" << '\n'
    << "4. Exit Program" << '\n';
}
void UI::menu(STATE* SYSTEM_STATE)
{
    // main menu loop
    int sel = 0;

    while(true)
    {
      print_menu();

      while(!this->Scanner.readint(&sel));
      switch (sel) {
        case 1:
          card_menu(SYSTEM_STATE);
          break;
        case 2:
          display_cards(SYSTEM_STATE);
          break;
        case 3:
          fake_scan(SYSTEM_STATE);
          break;
        case 4:
          std::cout << "exiting..." << '\n';
          return;
        default:
          std::cout << "Invalid input..." << '\n';
          break;
      }
    }
}
void UI::display_cards(STATE* SYSTEM_STATE)
{
    // prints all cards in list
    std::cout << "ID\tAccess\t\tDate" << '\n';
    for(Card& card: SYSTEM_STATE->card_list)
    {
      print_card(&card);
    }
}
void UI::print_card(Card *card)
{
    // prints a card

    // puts card date into string
    std::string date_string;
    Engine::format_card_time(card, date_string);

    // prints card
    std::cout << card->get_ID() << '\t' <<
    (card->get_access() ? "Has Access" : "Has no Access") <<
    '\t' << date_string << '\n';
}
void UI::card_menu(STATE* SYSTEM_STATE)
{
    std::string ID;
    std::cout << "Enter card ID" << '\n';
    while(!this->Scanner.readstring(ID,40));
    for( Card& card: SYSTEM_STATE->card_list)
    {
      if(ID == card.get_ID())
      {
        change_access(&card);
        return;
      }

    }
    std::cout << "No Card with that ID found." << '\n'
    << "Creating new.." << '\n';

    Engine::add_card(SYSTEM_STATE,ID);

    std::cout << "New Card " << ID << " added" << '\n';
}
void UI::change_access(Card *card)
{
  std::string sel;
  std::cout << "Card already exists," << " set access?(true/false): ";

  while(true)
  {

      while(!this->Scanner.readstring(sel,40));


      if(Engine::change_access(card,sel))
      {
          std::cout << "New access set" << '\n';
          break;
      }
      else
      {
          std::cout << "Invalid input" << '\n';
      }
  }
  std::cout << "\nCard Access changed" << '\n';

}
void UI::fake_scan(STATE *SYSTEM_STATE)
{
    Card *active_card = NULL;
    std::string sel;
    while(true)
    {
        std::cout << "Enter cardnumber to scan(x to exit)" << '\n';
        while(!this->Scanner.readstring(sel,40));
        if(sel == "x") return;
        if((active_card = Engine::get_card(SYSTEM_STATE,sel)) != NULL)
        {
            std::cout << '\n' << (active_card->get_access() ? "Light is green"
            : "Light is red") << '\n';
            continue;
        }

        std::cout << "No card with that ID found" << '\n';
    }
}
