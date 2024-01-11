#include "shell.h"

/**
 * getHistoryFile - Get the path to the history file
 * @info: Pointer to info_t struct containing environment information
 *
 * Retrieves the path to the history file by appending HIST_FILE to the HOME directory.
 *
 * Return: On success, returns a pointer to the history file path;
 *     on failure, returns NULL.
 */
char *getHistoryFile(info_t *info)
{
    char *homeDirectory, *filePath;
    size_t bufferSize;

    homeDirectory = getEnv(info, "HOME=");
    if (!homeDirectory)
    {
        return NULL;
    }

    bufferSize = strLen(homeDirectory) + strLen(HIST_FILE) + 2;
    filePath = malloc(sizeof(char) * bufferSize);

    if (!filePath)
    {
        return NULL;
    }

    filePath[0] = '\0'; /* Using '\0' to represent an empty string */
    stringCpy(filePath, homeDirectory);
    stringCat(filePath, "/");
    stringCat(filePath, HIST_FILE);

    return filePath;
}

/**
 * writeHistory - Write the history to a file
 * @info: Pointer to info_t struct containing history information
 *
 * Writes the history entries stored in info to a file.
 *
 * Return: On success, returns 1; on failure, returns -1.
 */
int writeHistory(info_t *info)
{
    char *fileName;
    int fileDescriptor;
    list_t *currentNode;

    fileName = getHistoryFile(info);

    if (!fileName)
    {
        return -1;
    }

    fileDescriptor = open(fileName, O_CREAT | O_TRUNC | O_RDWR, 0644);
    free(fileName);

    if (fileDescriptor == -1)
    {
        return -1;
    }

    currentNode = info->history;

    while (currentNode)
    {
        putsFd(currentNode->str, fileDescriptor);
        putFd('\n', fileDescriptor);
        currentNode = currentNode->next;
    }

    putFd(BUF_FLUSH, fileDescriptor);
    close(fileDescriptor);

    return 1;
}

/**
 * readHistory - Read the history from a file
 * @info: Pointer to info_t struct for storing history
 *
 * Reads the history entries from a file and populates info.
 *
 * Return: On success, returns the number of history entries read;
 *     on failure, returns 0.
 */
int readHistory(info_t *info)
{
    int i, last = 0, lineCount = 0;
    ssize_t fileDescriptor, readLength, fileSize = 0;
    struct stat fileStat;
    char *buffer = NULL, *fileName = getHistoryFile(info);

    if (!fileName)
        return 0;

    fileDescriptor = open(fileName, O_RDONLY);
    free(fileName);

    if (fileDescriptor == -1)
        return 0;

    if (!fstat(fileDescriptor, &fileStat))
        fileSize = fileStat.st_size;

    if (fileSize < 2)
        return 0;

    buffer = malloc(sizeof(char) * (fileSize + 1));

    if (!buffer)
        return 0;

    readLength = read(fileDescriptor, buffer, fileSize);
    buffer[fileSize] = 0;

    if (readLength <= 0)
        return free(buffer), 0;

    close(fileDescriptor);

    for (i = 0; i < fileSize; i++)
        if (buffer[i] == '\n')
        {
            buffer[i] = 0;
            buildHistoryList(info, buffer + last, lineCount++);
            last = i + 1;
        }

    if (last != i)
        buildHistoryList(info, buffer + last, lineCount++);

    free(buffer);
    info->histcount = lineCount;

    while (info->histcount-- >= HIST_MAX)
        deleteNodeAtIndex(&(info->history), 0);

    renumHistory(info);

    return info->histcount;
}

/**
 * buildHistoryList - Build a history list from a buffer
 * @info: Pointer to info_t struct for storing history
 * @buffer: Buffer containing history entries
 * @lineCount: Number of history entries in the buffer
 *
 * Builds a history list from a buffer of history entries.
 *
 * Return: Always returns 0.
 */
int buildHistoryList(info_t *info, char *buffer, int lineCount)
{
    list_t *result;
    list_t *currentNode = NULL;

    if (info->history)
    {
        currentNode = info->history;
    }

    result = addNodeEnd(&currentNode, buffer, lineCount);

    if (!info->history)
    {
        info->history = result;
    }

    return 0;
}

/**
 * renumHistory - Renumber history entries
 * @info: Pointer to info_t struct containing history information
 *
 * Renumbers the history entries in info.
 *
 * Return: The number of history entries after renumbering.
 */
int renumHistory(info_t *info)
{
    int i = 0;
    list_t *currentNode = info->history;

    while (currentNode)
    {
        currentNode->num = i++;
        currentNode = currentNode->next;
    }

    info->histcount = i;
    return info->histcount;
}
