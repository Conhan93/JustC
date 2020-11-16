#include "utils\state.h"
#include "UI.h"
#include <iostream>





int main()
{
    // create state and interface
    STATE SYSTEM_STATE = STATE();
    UI Interface = UI();

    // start
    Interface.menu(&SYSTEM_STATE);


    return 0;

}
