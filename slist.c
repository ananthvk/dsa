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

size_t slist_size(struct slist_node *head)
{
    size_t sz = 0;
    for (struct slist_node *t = head; t != NULL; t = t->next)
        sz++;
    return sz;
}

struct slist_node *sample_list(void)
{
    struct slist_node *list = NULL;
    slist_push(&list, 3);
    slist_push(&list, 3);
    slist_push(&list, 1);
    slist_push(&list, 3);
    slist_push(&list, 2);
    slist_push(&list, 5);
    slist_push(&list, 4);
    slist_push(&list, 3);
    slist_push(&list, 2);
    slist_push(&list, 1);
    return list;
}

size_t slist_count(struct slist_node *n, int key)
{
    size_t count = 0;
    for (; n != NULL; n = n->next)
    {
        if (n->data == key)
            ++count;
    }
    return count;
}

struct slist_node *slist_node_at(struct slist_node *n, size_t index)
{
    size_t count = 0;
    for (; n != NULL; n = n->next)
    {
        if (count == index)
            return n;
        ++count;
    }
    return NULL;
}

int slist_pop(struct slist_node **head)
{
    if (head == NULL || *head == NULL)
    {
        // TODO: panic instead of ignoring the error if the head is null
        return -1;
    }
    struct slist_node *next_node = (*head)->next;
    free(*head);
    *head = next_node;
    return 0;
}