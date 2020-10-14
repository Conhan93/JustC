#include <stdbool.h>

typedef enum
{	// Literally just return codes
	INPUT_RESULT_OK, // == 0 -- so if GetInput() returns 0 it was sucessfull
	INPUT_RESULT_TOO_LONG, // == 1 -- if it returns this there was buffer overflow basiclly
	INPUT_RESULT_NO_INPUT // == 2 -- if this it couldn't read any input
} INPUT_RESULT;

// function prototypes
INPUT_RESULT GetInput(char* prompt, char* buff, int maxSize);
bool GetInputInt(char* prompt, int* value);
bool GetInputFloat(char* prompt, float* value);
bool GetInputChar(char* prompt, char* value);