#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "map.h"

/*
 * Requires keeping track of how many times each character is seen. It looks
 * like it may require a map structure due to the fact that the given list is
 * not necessarily in order.
 */

int main(int argc, char **argv) {
    if(argc != 2) {
        return 1;
    }

    CharMap map = initMap();

    for(char *str = argv[1]; *str != 0; ++str) {
        insertMap(map, *str);
    }

    printMapContents(map);

    cleanupMap(map);
    return 0;
}
