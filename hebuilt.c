#include "shell.h"

/**
 * myHelp - Displays command-line arguments.
 * @info: A pointer to the info_t structure.
 *
 * Return: Always returns 0.
 */
int myHelp(info_t *info)
{
    char **arguments;
    int i;

    arguments = info->argv;
    _puts("Help function called. Displaying command-line arguments:\n");

    for (i = 0; arguments[i] != NULL; i++)
    {
        _puts(arguments[i]);
        _puts("\n");
    }

    return 0;
}

/**
 * myCd - Change the current working directory.
 * @info: A pointer to the info_t structure.
 *
 * Return: Always returns 0.
 */
int myCd(info_t *info)
{
    char *currentDirectory, *targetDirectory, buffer[1024];
    int chdirReturn;

    currentDirectory = getcwd(buffer, 1024);
    if (!currentDirectory)
        _puts("Failed to get the current directory.\n");

    if (!info->argv[1])
    {
        targetDirectory = getEnv(info, "HOME=");
        if (!targetDirectory)
            targetDirectory = getEnv(info, "PWD=");
    }
    else if (stringCmp(info->argv[1], "-") == 0)
    {
        targetDirectory = getEnv(info, "OLDPWD=");
        if (!targetDirectory)
        {
            _puts(currentDirectory);
            putChar('\n');
            return 1;
        }
    }
    else
    {
        targetDirectory = info->argv[1];
    }
    chdirReturn = chdir(targetDirectory);
    if (chdirReturn == -1)
    {
        printError(info, "can't cd to");
        ePuts(info->argv[1]);
        ePutChar('\n');
    }
    else
    {
        SetEnv(info, "OLDPWD", getEnv(info, "PWD="));
        SetEnv(info, "PWD", getcwd(buffer, 1024));
    }
    return 0;
}

/**
 * myExit - Exit the shell with an optional exit status.
 * @info: A pointer to the info_t structure.
 *
 * Return: The exit status code.
 */
int myExit(info_t *info)
{
    static int exitStatus;

    if (info->argv[1])
    {
        int exitCode = errAtoi(info->argv[1]);

        if (exitCode == -1)
        {
            info->status = 2;
            printError(info, "Illegal number: ");
            ePuts(info->argv[1]);
            ePutChar('\n');
            exitStatus = 1;
        }
        else
        {
            info->err_num = exitCode;
            exitStatus = -2;
        }
    }
    else
    {
        info->err_num = -1;
        exitStatus = -2;
    }

    return exitStatus;
}
