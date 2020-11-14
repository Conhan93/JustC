#include "readinput.h"

bool ReadInput::readline(char* buffer, size_t buffersize)
{
    char* input_string = NULL;

    char read_char = 0;
    int iteration = 1;
    input_string = (char*)malloc(sizeof(char));

    do
    {
        if ((read_char = fgetc(stdin)) != EOF && read_char != '\n')
        {
            input_string[iteration - 1] = read_char;
            input_string = (char*)realloc(input_string, sizeof(char) * (iteration + 1));
        }
        else
        {

            input_string[iteration - 1] = '\0';
            break;
        }
        iteration++;

    } while (1);

    strncpy(buffer, input_string, buffersize < iteration ? buffersize : iteration);
    buffer[buffersize < iteration ? (buffersize - 1) : (iteration - 1)] = '\0';
    free(input_string);
    return buffersize < iteration ? false : true;
}
bool ReadInput::readint(int* value,  int base)
{
    int temp = INT_MIN;
    char buffer[100];
    if (readline(buffer, sizeof(buffer)))
    {
        temp = strtol(buffer, NULL, base);
        if (temp != INT_MIN)
        {
            *value = temp;
            return true;
        }
    }
    return false;
}
bool ReadInput::readchar(char* character)
{
    char temp = 0;
    char buffer[100];
    if (readline(buffer, sizeof(buffer)))
    {
        temp = buffer[0];
        if (isalpha(temp))
        {
            *character = temp;
            return true;
        }
    }
    return false;
}
bool ReadInput::readfloat(float* value)
{
    float temp = FLT_MIN;
    char buffer[100];
    if (readline(buffer, sizeof(buffer)))
    {
        temp = strtof(buffer,NULL);
        if (temp != FLT_MIN)
        {
            *value = temp;
            return true;
        }
    }
    return false;

}
