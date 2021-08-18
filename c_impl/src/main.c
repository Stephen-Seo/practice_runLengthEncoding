#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Requires keeping track of how many times each character is seen.
 * Must keep track of given order, and a map is not necessary.
 */

#define INIT_ITEM_SIZE 16

typedef struct Item {
    char key;
    int value;
} Item;

int main(int argc, char **argv) {
    if(argc != 2) {
        return 1;
    }

    Item *items = calloc(INIT_ITEM_SIZE, sizeof(Item));
    size_t size = 0;
    size_t capacity = INIT_ITEM_SIZE;

    for(const char *s = argv[1]; *s != 0; ++s) {
        if(size > 0 && items[size-1].key == *s) {
            items[size-1].value += 1;
        } else {
            if(size == capacity) {
                Item *new_items = calloc(capacity * 2, sizeof(Item));
                memcpy(new_items, items, size * sizeof(Item));
                free(items);
                items = new_items;
                capacity *= 2;
            }

            items[size].key = *s;
            items[size].value = 1;
            ++size;
        }
    }

    for(size_t i = 0; i < size; ++i) {
        printf("%c count of %d\n", items[i].key, items[i].value);
    }

    free(items);
    return 0;
}
