#ifndef SLIST_H
#define SLIST_H
#include <stddef.h>
#include <stdint.h>

// Provides an implementation for a singly linked list in C
// along with various methods for other operations

// TODO: A list struct with variables such as size, last, etc

struct slist_node
{
    int data;
    struct slist_node *next;
};

// Solve linked list puzzles from here
// http://cslibrary.stanford.edu/105/LinkedListProblems.pdf

// Generates a sample list to run linked list functions without taking input (for development)
struct slist_node *sample_list(void);

// Count the number of occurences of key in the linked list
size_t slist_count(struct slist_node *head, int key);

// Allocates memory for a single slist_node, calls exit() if memory allocation fails
struct slist_node *wmalloc(void);

// Reads a space separated list of numbers from standard input and creates a new list
struct slist_node *slist_read(void);

// Print the list to standard output
void slist_display(struct slist_node *head);

// Finds the size of the list, O(n)
size_t slist_size(struct slist_node *head);

// Returns the node at the given index, NULL if the index is invalid
struct slist_node *slist_node_at(struct slist_node *head, size_t index);

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