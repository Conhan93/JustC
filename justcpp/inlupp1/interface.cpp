#include <iostream>
#include "interface.h"



Interface::Interface()
{
  this->Scanner = ReadInput();
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

    printf("\nID\t\t\tACCESS\t\t\tDATE ADDED\n"
    "------------------------------------------------------------");

    for (int index = 0; index < SYSTEM_STATE->nr_cards; index++)
    {
        format_date_string(
            SYSTEM_STATE->card_list[index].date_added,
            date_string,
            sizeof(date_string)
        );

        printf("\n%-20s\t%-20s\t%s",
            SYSTEM_STATE->card_list[index].ID,
            SYSTEM_STATE->card_list[index].access ? "Access" : "No Access",
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
    if (valid_id(new_card_id))
    {
        if ((active_card = get_card(SYSTEM_STATE->card_list, SYSTEM_STATE->nr_cards, new_card_id)) == NULL)
        {
            if (add_new_card())
                add_card(SYSTEM_STATE, new_card_id);
            return;
        }
        else
        {
            int new_access = 0;

            printf("\nThis card has %s, enter 1 for access, 2 for no access",
                active_card->access ? "access" : "no access");
            // sets new access for card
            if (Scanner.readint(&new_access))
            {
                if (new_access == 0 || new_access == 1)
                    active_card->access = new_access;

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

            active_card = get_card(
                SYSTEM_STATE->card_list,
                SYSTEM_STATE->nr_cards,
                search_term
            );
        }
        else invalid_input();
    }
    return active_card;
}
