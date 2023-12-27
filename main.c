#include "slist.h"

int main() {
    struct slist_node* list = slist_read();
    slist_push(&list, -999);
    slist_push(&list, 10000);
    slist_display(list);
    slist_free(&list);
}