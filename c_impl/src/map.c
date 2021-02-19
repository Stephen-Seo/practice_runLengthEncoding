#include "map.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

CharMap initMap() {
    CharMap map = (CharMap){0, MAP_INIT_SIZE, 0};

    map.buckets = calloc(MAP_INIT_SIZE, sizeof(Bucket));
    for(unsigned int i = 0; i < MAP_INIT_SIZE; ++i) {
        map.buckets[i].array = calloc(MAP_BUCKET_INIT_SIZE, sizeof(Item));
        map.buckets[i].capacity = 4;
    }

    return map;
}

void cleanupMap(CharMap map) {
    for(unsigned int i = 0; i < map.capacity; ++i) {
        free(map.buckets[i].array);
    }
    free(map.buckets);
}

void insertMap(CharMap map, char item) {
    // TODO recreate buckets when limit is reached
    // though this is for practice, so it's not really necessary
    unsigned int bucket_id = hasher(item) % map.capacity;
    // first check if char exists in bucket
    unsigned int i = 0;
    for(; i < map.buckets[bucket_id].size; ++i) {
        if(map.buckets[bucket_id].array[i].key == item) {
            break;
        }
    }

    if(i < map.buckets[bucket_id].size) {
        // exists in bucket, just increment the value
        map.buckets[bucket_id].array[i].value += 1;
    } else {
        // does not exist, check if capacity is there for new entry
        // and increase capacity if there isn't
        if(map.buckets[bucket_id].capacity == map.buckets[bucket_id].size) {
            Item *new_array = malloc(sizeof(Item)
                    * map.buckets[bucket_id].capacity * 2);
            memcpy(new_array, map.buckets[bucket_id].array, map.buckets[bucket_id].capacity * sizeof(Item));
            free(map.buckets[bucket_id].array);
            map.buckets[bucket_id].array = new_array;
            map.buckets[bucket_id].capacity *= 2;
        }

        map.buckets[bucket_id].array[map.buckets[bucket_id].size++] = (Item){item, 1};
    }
}

unsigned int getMap(CharMap map, char item) {
    unsigned int bucket_id = hasher(item) % map.capacity;
    for(unsigned int i = 0; i < map.buckets[bucket_id].size; ++i) {
        if(map.buckets[bucket_id].array[i].key == item) {
            return map.buckets[bucket_id].array[i].value;
        }
    }
    return 0;
}

void printMapContents(CharMap map) {
    for(unsigned int i = 0; i < map.capacity; ++i) {
        for(unsigned int j = 0; j < map.buckets[i].capacity; ++j) {
            if(map.buckets[i].array[j].value > 0) {
                printf("%c has %d entries\n", map.buckets[i].array[j].key,
                        map.buckets[i].array[j].value);
            }
        }
    }
}

unsigned int hasher(char item) {
    // really crappy hasher
    return (((unsigned int)item) + 17) * 59;
}
