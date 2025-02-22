#include "cache.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CACHE_SIZE 10

CacheEntry cache[CACHE_SIZE];
int cache_top = -1;

void initialize_cache() {
    memset(cache, -1, sizeof(cache));
}

int get_from_cache(int rod_length, int *total_value, int *cut_counts, int *remaining_length) {
    if (cache_top >= 0 && cache[cache_top].rod_length == rod_length) {
        *total_value = cache[cache_top].total_value;
        memcpy(cut_counts, cache[cache_top].cut_counts, sizeof(cache[cache_top].cut_counts));
        *remaining_length = cache[cache_top].remaining_length;
        return 1;
    }
    return 0;
}

void add_to_cache(int rod_length, int total_value, int *cut_counts, int remaining_length) {
    if (cache_top < CACHE_SIZE - 1) {
        cache[++cache_top] = (CacheEntry){rod_length, total_value, {0}, remaining_length};
        memcpy(cache[cache_top].cut_counts, cut_counts, sizeof(cache[cache_top].cut_counts));
    }
}