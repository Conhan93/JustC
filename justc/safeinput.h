#include <stdbool.h>

typedef enum
{
	INPUT_RESULT_OK,
	INPUT_RESULT_TOO_LONG,
	INPUT_RESULT_NO_INPUT
} INPUT_RESULT;

INPUT_RESULT GetInput(char* prompt, char* buff, int maxSize);
bool GetInputInt(char* prompt, int* value);
bool GetInputFloat(char* prompt, float* value);
bool GetInputChar(char* prompt, char* value);