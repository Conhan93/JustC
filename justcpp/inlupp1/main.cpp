#include "state.h"







int main()
{
    STATE SYSTEM_STATE = STATE("COM3");

    SYSTEM_STATE.interface::main_loop(&SYSTEM_STATE);

    return 0;

}
