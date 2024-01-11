#include "shell.h"

/**
 * _strnCpy - Copy at most n characters from src to dest
 * @dest: Destination string
 * @src: Source string
 * @n: Maximum number of characters to copy
 *
 * Return: A pointer to the destination string (dest).
 */
char *_strnCpy(char *destination, char *source, int count)
{
    char *result = destination;
    int index = 0;

    while (index < count)
    {
        if (source[index] != '\0')
        {
            destination[index] = source[index];
        }
        else
        {
            while (index < count)
            {
                destination[index] = '\0';
                index++;
            }

            break;
        }

        index++;
    }

    return result;
}

/**
 * _strnCat - Concatenate at most n characters from src to dest
 * @dest: Destination string
 * @src: Source string
 * @n: Maximum number of characters to concatenate
 *
 * Return: A pointer to the destination string (dest).
 */
char *_strnCat(char *destination, const char *source, int count)
{
    char *result = destination;
    int destIndex = 0, srcIndex = 0;

    /* Move to the end of the destination string */
    while (destination[destIndex] != '\0')
    {
        destIndex++;
    }

    /* Concatenate characters from src to dest, up to a maximum of n characters */
    while (source[srcIndex] != '\0' && srcIndex < count)
    {
        destination[destIndex] = source[srcIndex];
        destIndex++;
        srcIndex++;
    }

    /* Ensure the destination string is null-terminated */
    destination[destIndex] = '\0';

    return result;
}

/**
 * _strChr - Search for the first occurrence of a character in a string
 * @str: The input string
 * @character: The character to search for
 *
 * Return: A pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found.
 */
char *_strChr(char *string, char character)
{
    while (*string != '\0')
    {
        if (*string == character)
            return string;
        string++;
    }

    return NULL;
}
