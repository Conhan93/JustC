#include "card.h"


Card::Card(char* new_id)
{
  strcpy(this->ID, new_id);
  this->access = false;
  this->date_added = time(NULL);
}
void Card::get_id(char* str)
{
  strcpy(str,this->ID);
}
bool Card::get_access()
{
  return this->access;
}
std::time_t Card::get_date()
{
  return this->date_added;
}
void Card::set_access(bool access)
{
  this->access = access;
}
