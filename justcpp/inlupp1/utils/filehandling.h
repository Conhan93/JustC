#ifndef FILE_HANDLING_INCLUDED
#define FILE_HANDLING_INCLUDED
#include "state.h"
#include <string>



class FileHandler
{
    private:
      std::string filename;
      std::string fileextension;
      std::string filepath;

    public:
      FileHandler();
      bool save_to_file(STATE *SYSTEM_STATE);
      bool load_from_file(STATE *SYSTEM_STATE);

};
#endif
