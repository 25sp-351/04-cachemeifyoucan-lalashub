#include "cache.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CACHE_SIZE 10

CacheEntry cache[CACHE_SIZE];
int cache_index = 0;

void initialize_cache() {
    memset(cache, -1, sizeof(cache));
}

int get_from_cache(int rod_length, int *total_value, int *cut_counts, int *remaining_length) {
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].rod_length == rod_length) {
            *total_value = cache[i].total_value;
            memcpy(cut_counts, cache[i].cut_counts, sizeof(cache[i].cut_counts));
            *remaining_length = cache[i].remaining_length;
            return 1;
        }
    }
    return 0;
}

void add_to_cache(int rod_length, int total_value, int *cut_counts, int remaining_length) {
    cache[cache_index % CACHE_SIZE] = (CacheEntry){rod_length, total_value, {0}, remaining_length};
    memcpy(cache[cache_index % CACHE_SIZE].cut_counts, cut_counts, sizeof(cache[cache_index % CACHE_SIZE].cut_counts));
    cache_index++;
}