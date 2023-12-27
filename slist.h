#ifndef SLIST_H
#define SLIST_H
#include <stdlib.h>

// Provides an implementation for a singly linked list in C
// along with various methods for other operations

// TODO: A list struct with variables such as size, last, etc

struct sslist_node
{
    int data;
    void *next;
};

// Allocates memory for a single slist_node, calls exit() if memory allocation fails
struct slistslist_node* wmalloc();

// Reads a space separated list of numbers from standard input and creates a new list
struct slist_node *slist_read();

// Print the list to standard output
void display(const struct slist_node *head);

// Finds the size of the list
size_t slist_size(const struct slist_node *head);

// Returns the node at the given index, NULL if the index is invalid
struct slist_node *slist_slist_node_at(size_t index);

// Adds a new node to the head of the list, O(1) operation, returns the created node
struct slist_node *slist_push(struct slist_node **head, int value);

// Adds a node to the end of the list, O(n) operation
// @param head pointer to head node pointer
// @param value value to add to the list
// @return the created node
struct slist_node *slist_append(struct slist_node **head, int value);

// Inserts the node after the given key
// @return If the key is not found, returns NULL, otherwise returns the new node
struct slist_node *slist_insert_after(struct slist_node **head, int key, int value);

// Inserts the slist_node before the given key
// @return If the key is not found, returns NULL, otherwise returns the new node
struct slist_node *slist_insert_before(struct slist_node **head, int key, int value);

// Deletes the first element of the list
int slist_pop(struct slist_node **head);

// Deletes the last element of the list, O(n) operation
int slist_delete_end(struct slist_node **head);

// Deletes the first element with the given key
int slist_delete(struct slist_node **head, int key);

// Deletes the element after the element with the given key
struct slist_node *slist_delete_after(struct slist_node **head, int key);

// Deletes the element before the element with the given key
struct slist_node *slist_delete_before(struct slist_node **head, int key);

// Concatenates src into destination
// Note: This performs a shallow copy and modifications in one list, reflect in the other
struct slist_node *slist_concat(struct slist_node *dst, struct slist_node *src);

// Free the list
void slist_free(struct slist_node **head);

#endif