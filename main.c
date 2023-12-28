#include "slist.h"
#include <stdio.h>

int main()
{
    struct slist_node *list = sample_list();
    // slist_push(&list, -999);
    // slist_push(&list, 10000);
    // slist_push(&(list->next), 500);
    slist_display(list);
    printf("Size of linked list is: %d\n", (int)slist_size(list));
    printf("Count of 0: %d\n", (int)slist_count(list, 0));
    printf("Count of 1: %d\n", (int)slist_count(list, 1));
    printf("Count of 2: %d\n", (int)slist_count(list, 2));
    printf("Count of 3: %d\n", (int)slist_count(list, 3));
    printf("Count of 4: %d\n", (int)slist_count(list, 4));
    printf("Count of 5: %d\n", (int)slist_count(list, 5));
    printf("Count of 6: %d\n", (int)slist_count(list, 6));
    
    printf("list[0] = %d\n", slist_node_at(list, 0)->data);
    printf("list[1] = %d\n", slist_node_at(list, 1)->data);
    printf("list[2] = %d\n", slist_node_at(list, 2)->data);
    printf("list[3] = %d\n", slist_node_at(list, 3)->data);
    printf("list[4] = %d\n", slist_node_at(list, 4)->data);
    printf("list[5] = %d\n", slist_node_at(list, 5)->data);
    printf("list[6] = %d\n", slist_node_at(list, 6)->data);
    printf("list[7] = %d\n", slist_node_at(list, 7)->data);
    printf("list[8] = %d\n", slist_node_at(list, 8)->data);
    printf("list[9] = %d\n", slist_node_at(list, 9)->data);

    printf("list[10] = %p\n", (void*)slist_node_at(list, 10));
    
    while(!slist_pop(&list))
        ;
    slist_insert_at(&list, 0, 3);
    slist_display(list);
    slist_free(&list);

    slist_insert_at(&list, 8, 6);
    slist_insert_at(&list, 8, 12);
    slist_insert_at(&list, 9, 13);
    slist_display(list);
    slist_free(&list);

    slist_insert_at(&list, 0, 21);
    slist_insert_at(&list, 0, 12);
    slist_display(list);
    slist_free(&list);

    slist_push(&list, 5);
    slist_push(&list, 8);
    slist_push(&list, 11);
    slist_push(&list, 14);
    slist_push(&list, 17);
    slist_insert_at(&list, 2, 12);
    slist_display(list);
    slist_free(&list);
    
    slist_sorted_insert(&list, 3);
    slist_sorted_insert(&list, -1);
    slist_sorted_insert(&list, 0);
    slist_sorted_insert(&list, 8);
    slist_sorted_insert(&list, 16);
    slist_sorted_insert(&list, 20);
    slist_sorted_insert(&list, 4);
    slist_sorted_insert(&list, 12);
    slist_sorted_insert(&list, 9);
    slist_sorted_insert(&list, 1000);
    slist_sorted_insert(&list, -1000);
    slist_display(list);
    slist_free(&list);
}