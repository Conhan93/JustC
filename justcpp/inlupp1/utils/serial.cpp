#include "serial.h"


Serial::Serial(char* portName)
{
	//SERIALPORT port;
  
	this->connected = false;

	this->handler = CreateFileA(portName,
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (this->handler == INVALID_HANDLE_VALUE) {
		if (GetLastError() == ERROR_FILE_NOT_FOUND) {
			printf("ERROR: Handle was not attached. Reason: %s not available\n", portName);
		}
		else
		{
			printf("ERROR!!!");
		}
	}
	else {
		DCB dcbSerialParameters = { 0 };

		if (!GetCommState(this->handler, &dcbSerialParameters)) {
			printf("failed to get current serial parameters");
		}
		else {
			dcbSerialParameters.BaudRate = CBR_9600;
			dcbSerialParameters.ByteSize = 8;
			dcbSerialParameters.StopBits = ONESTOPBIT;
			dcbSerialParameters.Parity = NOPARITY;
			dcbSerialParameters.fDtrControl = DTR_CONTROL_ENABLE;

			if (!SetCommState(this->handler, &dcbSerialParameters))
			{
				printf("ALERT: could not set Serial port parameters\n");
			}
			else {
				this->connected = true;
				PurgeComm(this->handler, PURGE_RXCLEAR | PURGE_TXCLEAR);
				Sleep(ARDUINO_WAIT_TIME);
			}
		}
	}
	//return port;
}

void Serial::SerialReadToNewLine(Serial port, char* buffer, unsigned int buf_size)
{
	ClearCommError(this->handler, &(this->errors), &(this->status));
	int pos = 0;
	while (true)
	{
		char b[10];
		DWORD bytesRead;
		if (ReadFile(this->handler, b, 1, &bytesRead, NULL) == 1)
		{
			if (b[0] == '\n')
			{
				buffer[pos] = 0;
				return;
			}
			buffer[pos] = b[0];
			pos++;
		}
	}
}


int Serial::SerialReadPort(Serial port, char* buffer, unsigned int buf_size)
{
	DWORD bytesRead;
	unsigned int toRead = 0;

	ClearCommError(this->handler, &(this->errors), &(this->status));

	if (this->status.cbInQue > 0) {
		if (this->status.cbInQue > buf_size) {
			toRead = buf_size;
		}
		else toRead = this->status.cbInQue;
	}

	memset(buffer, 0, buf_size);

	if (ReadFile(this->handler, buffer, toRead, &bytesRead, NULL)) return bytesRead;

	return 0;
}

bool Serial::SerialWritePort(Serial port, char* buffer, unsigned int buf_size)
{
	DWORD bytesSend;

	if (!WriteFile(this->handler, (void*)buffer, buf_size, &bytesSend, 0)) {
		ClearCommError(this->handler, &(this->errors), &(this->status));
		return false;
	}
	else return true;
}

bool Serial::SerialIsConnected(Serial port)
{

	if (!ClearCommError(this->handler, &(this->errors), &(this->status)))
		port.connected = false;

	return this->connected;
}

Serial::~Serial()
{
	CloseHandle(this->handler);
}
