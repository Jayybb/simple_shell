#include "shell.h"

/**
 * errAtoi - This converts a string to an integer.
 * @inputStr: The input string to convert.
 *
 * Return: The integer value or INT_MIN/INT_MAX on overflow/underflow.
 */
int errAtoi(char *inputStr)
{
    int outputResult = 0;
    int outputSign = 1;

    if (*inputStr == '-' || *inputStr == '+')
    {
        if (*inputStr == '-')
            outputSign = -1;
        inputStr++;
    }

    for (; *inputStr != '\0'; inputStr++)
    {
        if (*inputStr >= '0' && *inputStr <= '9')
        {
            int currentDigit = *inputStr - '0';

            if (outputResult > (INT_MAX - currentDigit) / 10 || outputResult < (INT_MIN + currentDigit) / 10)
            {
                return ((outputSign == 1) ? INT_MAX : INT_MIN);
            }

            outputResult = outputResult * 10 + outputSign * currentDigit;
        }
        else
        {
            return (-1);
        }
    }

    return outputResult;
}

/**
 * printError - Prints an error message with formatting.
 * @errorInfo: Information about the error context.
 * @errorMessage: The error message to print.
 *
 * Returns: None.
 */
void printError(info_t *errorInfo, char *errorMessage)
{
    ePuts(errorInfo->fname);
    ePuts(": ");
    printD(errorInfo->line_count, STDERR_FILENO);
    ePuts(": ");
    ePuts(errorInfo->argv[0]);
    ePuts(": ");
    ePuts(errorMessage);
}

/**
 * printD - Prints an integer to a file descriptor.
 * @outputValue: The integer to print.
 * @outputFd: The file descriptor to print to.
 *
 * Returns: The number of characters printed.
 */
int printD(int outputValue, int outputFd)
{
    int (*outputPutChar)(char) = (outputFd == STDERR_FILENO) ? ePutChar : putChar;
    int outputCount = 0;
    int outputDivisor, outputDigit;
    bool outputLeadingZero;

    if (outputValue < 0)
    {
        outputPutChar('-');
        outputValue = -outputValue;
        outputCount++;
    }

    outputLeadingZero = true;

    for (outputDivisor = 1000000000; outputDivisor >= 1; outputDivisor /= 10)
    {
        outputDigit = outputValue / outputDivisor;
        outputValue %= outputDivisor;

        if (outputDigit > 0 || !outputLeadingZero)
        {
            outputPutChar('0' + outputDigit);
            outputCount++;
            outputLeadingZero = false;
        }
    }

    return outputCount;
}

/**
 * convertNum - Converts a number to a string with a specified base.
 * @inputNum: The number to convert.
 * @inputBase: The base for conversion (e.g., 10 for decimal).
 * @inputFlags: Flags for conversion options.
 *
 * Returns: The pointer to the converted string.
 */
char *convertNum(long int inputNum, int inputBase, int inputFlags)
{
    static char outputBuffer[50];
    static char *outputArray;
    char outputSign = 0;
    char *outputPtr;
    unsigned long outputNum = inputNum;

    outputArray = inputFlags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";

    if (!(inputFlags & CONVERT_UNSIGNED) && inputNum < 0)
    {
        outputSign = '-';
        outputNum = -inputNum;
    }

    outputPtr = &outputBuffer[49];
    *outputPtr = '\0';

    do
    {
        *--outputPtr = outputArray[outputNum % inputBase];
        outputNum /= inputBase;
    } while (outputNum != 0);

    if (outputSign)
        *--outputPtr = outputSign;

    return outputPtr;
}

/**
 * removeComm - Removes a comment from a string.
 * @commentBuffer: The input string to remove the comment from.
 *
 * Returns: None.
 */
void removeComm(char *commentBuffer)
{
    int commentIndex = 0;
    int commentStart = -1;

    while (commentBuffer[commentIndex] != '\0')
    {
        if (commentBuffer[commentIndex] == '#' && (commentIndex == 0 || commentBuffer[commentIndex - 1] == ' '))
        {
            commentStart = commentIndex;
            break;
        }

        commentIndex++;
    }

    if (commentStart != -1)
    {
        commentBuffer[commentStart] = '\0';
    }
}
