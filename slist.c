#include "slist.h"
#include <stdio.h>
#include <stdlib.h>

struct slist_node *wmalloc()
{
    struct slist_node *new_node = (struct slist_node *)malloc(sizeof(struct slist_node));
    if (new_node == NULL)
    {
        printf("Could not allocate memory for node\n");
        exit(1);
    }
    return new_node;
}

struct slist_node *slist_read(void)
{
    printf("Enter integers, 0 to quit\n");
    int item;
    // TODO: Handle return of scanf
    scanf("%d", &item);
    struct slist_node *list = NULL;
    while (item != 0)
    {
        slist_push(&list, item);
        scanf("%d", &item);
    }
    return list;
}

void slist_display(struct slist_node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct slist_node *slist_push(struct slist_node **head, int item)
{
    if (head == NULL)
    {
        return NULL;
    }

    struct slist_node *new_node = wmalloc();
    new_node->data = item;
    new_node->next = *head;
    *head = new_node;
    return new_node;
}

void slist_free(struct slist_node **head)
{
    struct slist_node *t = *head, *temp;
    if (head == NULL)
    {
        return;
    }
    while (t != NULL)
    {
        temp = t;
        t = t->next;
        free(temp);
    }
    *head = NULL;
}