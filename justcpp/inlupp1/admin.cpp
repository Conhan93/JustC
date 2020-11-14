#include "admin.h"


Admin::Admin()
{

}
bool Admin::valid_id(char* new_id)
{
    // checks if new card id input is valid or not
    char temp[STRLEN], delim[] = ".";
    char* digit;
    int counter = 0;

    strcpy(temp, new_id);

    digit = strtok(temp, delim);
    while (digit != NULL)
    {
        if (atoi(digit) > 255 || atoi(digit) <= 0) return false;

        else digit = strtok(NULL, delim);

        counter++;
    }
    return counter == 5 ? true : false;
}
Card* Admin::get_card(std::vector<Card>& card_list, std::vector<Card>::size_type nr_cards, char* search_term)
{
    /*   Loops through card list comparing ID:s and returns card with matching ID   */

    Card* active_card;
    char card_id[STRLEN];

    for (int index = 0; index < nr_cards; index++)
    {
        card_list[index].get_id(card_id);
        if (!strcmp(search_term, card_id))
            return active_card = &card_list[index];
    }
    // returns NULL if card is not found
    return NULL;
}
void Admin::format_date_string(time_t date_added, char* buffer, int buffersize)
{
    // Formats buffer string with the time stored in date_added
    struct tm* date_ptr;

    date_ptr = localtime(&date_added);

    strftime(buffer, buffersize, "%Y-%m-%d", date_ptr);
}
void Admin::add_card(STATE* SYSTEM_STATE, char* new_card_id)
{ /*
        Adds new card to list
  */
    SYSTEM_STATE->card_list.push_back(Card(new_card_id));

}
