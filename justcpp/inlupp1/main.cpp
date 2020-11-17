#include "utils\state.h"
#include "UI.h"
#include "utils\filehandling.h"
#include <iostream>





int main()
{
    // create state and interface
    STATE SYSTEM_STATE = STATE();
    UI Interface = UI();
    FileHandler file_handler = FileHandler();

    //file_handler.load_from_file(&SYSTEM_STATE);

    // start
    Interface.menu(&SYSTEM_STATE);

    //file_handler.save_to_file(&SYSTEM_STATE);


    return 0;

}
