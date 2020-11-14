#include <iostream>
#include "interface.h"



Interface::Interface(Admin state_admin)
{
  this->Scanner = ReadInput();
  this->admin = state_admin;
}
void Interface::main_loop(STATE* SYSTEM_STATE)
{
  int selection = 0;

  while (true)
  {
      selection = admin_menu();
      switch (selection)
      {
      case 1:
          //if (remote_open_door(&SYSTEM_STATE)) printf("\nDoor Open");
          //else printf("\nUnable to open door");
          break;
      case 2:
          list_cards(SYSTEM_STATE);
          break;
      case 4:
          change_card_access(SYSTEM_STATE);
          break;
      case 5:
          //save_to_file(&SYSTEM_STATE);
          break;
      case 6:
          //send_card(&SYSTEM_STATE);
          break;
      case 7:
          //if (clear_cards(SYSTEM_STATE)) printf("\nCards cleared");
          //else printf("\nUnable to clear cards");
          break;
      case 9:
          //SerialClose(SYSTEM_STATE.port);
          return;

      default:
          printf("\nError! invalid input.");
          break;
      }
    }
}
int Interface::admin_menu()
{
    /*  Prints main menu and gets menu input    */

    int selection = 0;

    printf("\n\n\n****ADMIN MENU****\n");
    printf("\n1.Remote Open Door"
        "\n2. List all cards in system"
        "\n4. Add/remove access"
        "\n5. Save cards to file"
        "\n6. Send a card to device"
        "\n7. Clear all cards on device"
        "\n9. Exit\n");

    while (!Scanner.readint(&selection)) invalid_input();

    return selection;
}
void Interface::list_cards(STATE* SYSTEM_STATE)
{
    // displays all cards in system.
    char date_string[STRLEN];
    char ID_string[STRLEN];

    printf("\nID\t\t\tACCESS\t\t\tDATE ADDED\n"
    "------------------------------------------------------------");

    for (int index = 0; index < SYSTEM_STATE->card_list.size(); index++)
    {
        admin.format_date_string(
            SYSTEM_STATE->card_list[index].get_date(),
            date_string,
            sizeof(date_string)
        );

        SYSTEM_STATE->card_list[index].get_id(ID_string);

        printf("\n%-20s\t%-20s\t%s",
            ID_string,
            SYSTEM_STATE->card_list[index].get_access() ? "Access" : "No Access",
            date_string
        );
    }
}
void Interface::change_card_access(STATE* SYSTEM_STATE)
{
    /*
        Handles changing card access value
    */
    Card* active_card = NULL;
    char new_card_id[STRLEN];

    printf("\nValid card in form x.x.x.x.x where x is an integer between 1"
           "and 255\nAnge Kortnr: ");

    while (Scanner.readline(new_card_id, sizeof(new_card_id))) invalid_input();
    if (admin.valid_id(new_card_id))
    {
        if ((active_card = admin.get_card(SYSTEM_STATE->card_list, SYSTEM_STATE->card_list.size(), new_card_id)) == NULL)
        {
            if (add_new_card())
                admin.add_card(SYSTEM_STATE->card_list, new_card_id);
            return;
        }
        else
        {
            int new_access = 0;

            printf("\nThis card has %s, enter 1 for access, 2 for no access",
                active_card->get_access() ? "access" : "no access");
            // sets new access for card
            if (Scanner.readint(&new_access))
            {
                if (new_access == 0 || new_access == 1)
                    active_card->set_access(new_access);

            }
            else invalid_input();
        }
    }
    else printf("\nInvalid ID...");


    printf("\nExiting access...");

}
Card* Interface::search_id(STATE* SYSTEM_STATE)
{
    /*  Interface for card ID search    */


    Card* active_card = NULL;
    char search_term[STRLEN];

    while (active_card == NULL)
    {
        printf("\nEnter card ID(type exit to quit): ");
        if (Scanner.readline(search_term, sizeof(search_term)))
        {
            if (!strcmp(search_term, "exit")) return NULL;

            active_card = admin.get_card(
                SYSTEM_STATE->card_list,
                SYSTEM_STATE->card_list.size(),
                search_term
            );
        }
        else invalid_input();
    }
    return active_card;
}
