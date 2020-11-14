#ifndef SERIAL_INCLUDED
#define SERIAL_INCLUDED

#include <windows.h>
#include <stdio.h>

#define ARDUINO_WAIT_TIME 2000
#define MAX_DATA_LENGTH 255

class Serial
{
    public:
      Serial(char* portName);
      ~Serial();
      void SerialReadToNewLine(Serial port, char* buffer, unsigned int buf_size);
      int SerialReadPort(Serial port, char* buffer, unsigned int buf_size);
      bool SerialWritePort(Serial port, char* buffer, unsigned int buf_size);
      bool SerialIsConnected(Serial port);
    private:
      HANDLE handler;
	    bool connected;
	    COMSTAT status;
	    DWORD errors;

};
#endif
