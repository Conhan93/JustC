
#include "card.h"
#include <cstring>

Card::Card(std::string ID)
{
    // default constructor
    this->ID = ID;
    this->access = false;
    this->date_added = time(NULL);
}
Card::Card(std::string ID, bool access, time_t date)
{
    // load from file -- constructor
    this->ID = ID;
    this->access = access;
    this->date_added = date;
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
void Card::set_time(time_t date_added)
{
    this->date_added = date_added;
}
std::string& Card::get_ID()
{
    return this->ID;
}
