#ifndef PRACTICE_MAP_H
#define PRACTICE_MAP_H

/*
 * map contains a limited amount of buckets. Hashing the key will associate that
 * key to a given bucket. When multiple keys are associated with the same
 * bucket, use an array to hold multiple. Requries keys be hashable and
 * equatable.
 */

#define MAP_LIMIT 0.75
#define MAP_INIT_SIZE 32
#define MAP_BUCKET_INIT_SIZE 4

typedef struct Item {
    char key;
    unsigned int value;
} Item;

typedef struct Bucket {
    Item *array;
    unsigned int capacity;
    unsigned int size;
} Bucket;

typedef struct CharMap {
    Bucket *buckets;
    unsigned int capacity;
    unsigned int size;
} CharMap;

CharMap initMap();
void cleanupMap(CharMap map);
void insertMap(CharMap map, char item);
unsigned int getMap(CharMap map, char item);
void printMapContents(CharMap map);

unsigned int hasher(char item);

#endif
