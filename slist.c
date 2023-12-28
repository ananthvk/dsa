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
        fprintf(stderr, "panic: passed pointer to head pointer is NULL\n");
        exit(1);
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
    if (head == NULL)
    {
        fprintf(stderr, "panic: passed pointer to head pointer is NULL\n");
        exit(1);
    }
    if (*head == NULL)
    {
        // TODO: panic instead of ignoring the error if the head is null
        return -1;
    }
    struct slist_node *next_node = (*head)->next;
    free(*head);
    *head = next_node;
    return 0;
}

struct slist_node *slist_insert_at(struct slist_node **head, size_t index, int value)
{
    struct slist_node *temp, *prev, *new_node;
    size_t i = 0;
    // There are 3 possible cases
    // 1. At index 0, call slist_push
    // 2. At index >= size-1, call slist_append
    // 3. Otherwise, find node at index-1, and insert the new node after it
    if (head == NULL)
    {
        // Handle this case when the pointer passed is NULL
        fprintf(stderr, "panic: passed pointer to head pointer is NULL\n");
        exit(1);
    }
    if (*head == NULL || index == 0)
    {
        return slist_push(head, value);
    }
    else
    {
        new_node = wmalloc();
        new_node->data = value;
        temp = *head;
        prev = *head;
        while (temp != NULL && i != index)
        {
            prev = temp;
            temp = temp->next;
            i += 1;
        }
        if (temp == NULL)
        {
            // Insert the node at the end
            new_node->next = NULL;
            prev->next = new_node;
        }
        else
        {
            new_node->next = temp;
            prev->next = new_node;
        }
        return new_node;
    }
}

struct slist_node *slist_sorted_insert(struct slist_node **head, int value)
{
    struct slist_node *t, *f, *new_node;
    if (head == NULL)
    {
        // Handle this case when the pointer passed is NULL
        fprintf(stderr, "panic: passed pointer to head pointer is NULL\n");
        exit(1);
    }
    if (*head == NULL || value < (*head)->data)
    {
        // The value is smaller than all other elements
        // Insert at beginning
        return slist_push(head, value);
    }
    t = *head;
    f = *head;
    while (t != NULL && t->data < value)
    {
        f = t;
        t = t->next;
    }
    new_node = wmalloc();
    new_node->data = value;
    new_node->next = t;
    f->next = new_node;
    return new_node;
}
