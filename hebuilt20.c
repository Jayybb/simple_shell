#include "shell.h"

/**
 * printAlias - Display an alias from a list node.
 * @node: Pointer to the list node containing the alias.
 *
 * This function displays an alias from a given list node.
 *
 * Return: 0 on success, 1 on failure.
 */
int printAlias(list_t *node)
{
    char *eqSignPos;
    char *aliasPart;

    if (node)
    {
        eqSignPos = _strChr(node->str, '=');
        for (aliasPart = node->str; aliasPart <= eqSignPos; aliasPart++)
            putChar(*aliasPart);

        putChar('\'');
        _puts(eqSignPos + 1);
        _puts("'\n");
        return 0;
    }

    return 1;
}

/**
 * unsetAlias - Remove an alias from the info structure.
 * @info: Pointer to the info structure.
 * @str: Alias to remove.
 *
 * This function removes an alias from the info structure.
 *
 * Return: 0 on success, 1 on failure.
 */
int unsetAlias(info_t *info, char *str)
{
    char *eqSignPos;
    char origChar;
    int result;

    eqSignPos = _strChr(str, '=');
    if (!eqSignPos)
        return 1;

    origChar = *eqSignPos;
    *eqSignPos = 0;

    result = deleteNodeAtIndex(&(info->alias), getNodeIndex
            (info->alias, nodeStartsWith(info->alias, str, -1)));

    *eqSignPos = origChar;
    return result;
}

/**
 * setAlias - Add an alias to the info structure.
 * @info: Pointer to the info structure.
 * @str: Alias to add.
 *
 * This function adds an alias to the info structure.
 *
 * Return: 0 on success, 1 on failure.
 */
int setAlias(info_t *info, char *str)
{
    char *eqSignPos = _strChr(str, '=');
    int result;

    if (!eqSignPos)
        return 1;

    if (!*++eqSignPos)
        return unsetAlias(info, str);

    unsetAlias(info, str);
    result = addNodeEnd(&(info->alias), str, 0) == NULL;
    return result;
}

/**
 * myAlias - Manage alias commands.
 * @info: Pointer to the info structure.
 *
 * This function manages alias commands,
 * including setting and displaying aliases.
 * Return: Always returns 0.
 */
int myAlias(info_t *info)
{
    int i;
    char *eqSignPos;
    list_t *currentNode;

    if (info->argc == 1)
    {
        currentNode = info->alias;
        while (currentNode)
        {
            printAlias(currentNode);
            currentNode = currentNode->next;
        }

        return 0;
    }

    for (i = 1; info->argv[i]; i++)
    {
        eqSignPos = _strChr(info->argv[i], '=');
        if (eqSignPos)
            setAlias(info, info->argv[i]);
        else
            printAlias(nodeStartsWith(info->alias, info->argv[i], '='));
    }

    return 0;
}

/**
 * myHistory - Display the command history.
 * @info: Pointer to the info structure.
 *
 * This function displays the command history.
 *
 * Return: Always returns 0.
 */
int myHistory(info_t *info)
{
    printList(info->history);
    return 0;
}
