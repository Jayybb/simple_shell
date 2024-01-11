#include "shell.h"

/**
 * addNode - Adds a new node at the beginning of a linked list.
 * @head: A pointer to the pointer to the head of the list.
 * @str: The string to be stored in the new node.
 * @num: An integer to be stored in the new node.
 *
 * Return: A pointer to the newly created node, or NULL on failure.
 */
list_t *addNode(list_t **head, const char *str, int num)
{
    list_t *newHead = NULL;
    list_t *newNode = NULL;

    if (!head)
        return NULL;

    newNode = (list_t *)malloc(sizeof(list_t));
    if (!newNode)
        return NULL;

    memSet((void *)newNode, 0, sizeof(list_t));
    newNode->num = num;

    if (str)
    {
        newNode->str = stringDup(str);
        if (!newNode->str)
        {
            free(newNode);
            return NULL;
        }
    }

    newNode->next = *head;
    *head = newNode;
    newHead = newNode;

    return newHead;
}

/**
 * addNodeEnd - Adds a new node at the end of a linked list.
 * @head: A pointer to the pointer to the head of the list.
 * @str: The string to be stored in the new node.
 * @num: An integer to be stored in the new node.
 *
 * Return: A pointer to the newly created node, or NULL on failure.
 */
list_t *addNodeEnd(list_t **head, const char *str, int num)
{
    list_t *newNode = NULL;
    list_t *currentNode = NULL;

    if (!head)
        return NULL;

    newNode = (list_t *)malloc(sizeof(list_t));
    if (!newNode)
        return NULL;

    memSet((void *)newNode, 0, sizeof(list_t));
    newNode->num = num;

    if (str)
    {
        newNode->str = stringDup(str);
        if (!newNode->str)
        {
            free(newNode);
            return NULL;
        }
    }

    currentNode = *head;
    if (currentNode)
    {
        while (currentNode->next)
            currentNode = currentNode->next;
        currentNode->next = newNode;
    }
    else
    {
        *head = newNode;
    }

    return newNode;
}

/**
 * printListStr - Prints the strings stored in the linked list.
 * @h: A pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t printListStr(const list_t *h)
{
    size_t nodeCount = 0;
    const list_t *currentNode = h;

    while (currentNode)
    {
        _puts(currentNode->str ? currentNode->str : "(nil)");
        _puts("\n");
        currentNode = currentNode->next;
        nodeCount++;
    }

    return nodeCount;
}

/**
 * deleteNodeAtIndex - Deletes a node at the specified index in the linked list.
 * @head: A pointer to the pointer to the head of the list.
 * @index: The index of the node to be deleted.
 *
 * Return: 1 on success, 0 on failure.
 */
int deleteNodeAtIndex(list_t **head, unsigned int index)
{
    list_t *currentNode = NULL;
    list_t *prevNode = NULL;
    unsigned int currentIndex = 0;

    if (!head || !*head)
        return 0;

    if (index == 0)
    {
        currentNode = *head;
        *head = (*head)->next;
        free(currentNode->str);
        free(currentNode);
        return 1;
    }

    currentNode = *head;
    while (currentNode)
    {
        if (currentIndex == index)
        {
            prevNode->next = currentNode->next;
            free(currentNode->str);
            free(currentNode);
            return 1;
        }

        currentIndex++;
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    return 0;
}

/**
 * freeList - Frees all nodes in the linked list and sets the head to NULL.
 * @headPtr: A pointer to the pointer to the head of the list.
 */
void freeList(list_t **headPtr)
{
    list_t *currentNode = NULL;
    list_t *nextNode = NULL;
    list_t *head = NULL;

    if (!headPtr || !*headPtr)
        return;

    head = *headPtr;
    currentNode = head;
    while (currentNode)
    {
        nextNode = currentNode->next;
        free(currentNode->str);
        free(currentNode);
        currentNode = nextNode;
    }

    *headPtr = NULL;
}
