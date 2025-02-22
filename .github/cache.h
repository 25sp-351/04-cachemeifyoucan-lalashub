#ifndef CACHE_H
#define CACHE_H

#define CACHE_SIZE 10

typedef struct {
    int rod_length;
    int total_value;
    int cut_counts[100];
    int remaining_length;
} CacheEntry;

void initialize_cache();
int get_from_cache(int rod_length, int *total_value, int *cut_counts, int *remaining_length);
void add_to_cache(int rod_length, int total_value, int *cut_counts, int remaining_length);

#endif
