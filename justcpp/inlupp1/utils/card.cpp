
#include "card.h"
#include <cstring>

Card::Card(std::string ID)
{
    this->ID = ID;
    this->access = false;
    this->date_added = time(NULL);
}
bool Card::get_access()
{
    return this->access;
}
void Card::set_access(bool new_access)
{
    this->access = new_access;
}
time_t* Card::get_time()
{
    return &this->date_added;
}
std::string& Card::get_ID()
{
    return this->ID;
}
