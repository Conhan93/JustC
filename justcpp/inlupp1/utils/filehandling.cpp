#include "filehandling.h"
#include <fstream>


FileHandler::FileHandler()
{
    this->filepath = "files\\";
    this->filename = "cards";
    this->fileextension = ".dat";
}
bool FileHandler::save_to_file(STATE *SYSTEM_STATE)
{
    std::ofstream write_file(this->filepath+this->filename+this->fileextension,
                        std::ios::out | std::ios::trunc);

    if(!write_file) return false;

    for(Card& card : SYSTEM_STATE->card_list)
    {
      write_file << card.get_ID() << std::endl;
      write_file << card.get_access() << std::endl;
      write_file << *card.get_time() << std::endl;
    }

    write_file.close();
    return true;
}
bool FileHandler::load_from_file(STATE *SYSTEM_STATE)
{
    Card read_card = Card("");
    std::ifstream read_file(this->filepath+this->filename+this->fileextension,
                           std::ios::out);
    std::string inputs, ID;
    bool access = 0;
    time_t date = 0;

    if(!read_file) return false;
    while(true)
    {
        read_file >> inputs;
        if(read_file.eof()) break;
        ID = inputs;
        read_file >> access;
        read_file >> date;

        SYSTEM_STATE->card_list.push_back(Card(ID, access, date));
    }

    read_file.close();
    return true;
}
