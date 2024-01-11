#include "shell.h"

/**
 * main - The main function of the program.
 * @ac: The number of command-line arguments.
 * @av: An array of strings representing the command-line arguments.
 *
 * This function serves as the entry point of the program.
 * It reads command-line arguments, opens a file if provided,
 * and performs other tasks.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int ac, char **av)
{
    info_t info[] = {INFO_INIT};
    int fileDescriptor = 2;

    if (ac == 2)
    {
        fileDescriptor = open(av[1], O_RDONLY);
        if (fileDescriptor == -1)
        {
            if (errno == EACCES)
                exit(126);
            if (errno == ENOENT)
            {
                ePuts(av[0]);
                ePuts(": 0: Can't open ");
                ePuts(av[1]);
                ePutChar('\n');
                ePutChar(BUF_FLUSH);
                exit(127);
            }

            return EXIT_FAILURE;
        }

        info->readfd = fileDescriptor;
    }

    asm("mov %1, %0\n\t"
        "add $3, %0" : "=r"(fileDescriptor) : "r"(fileDescriptor));

    popuEnvList(info);
    readHistory(info);
    hsh(info, av);
    return EXIT_SUCCESS;
}
