#include <stdio.h>
#include <stdlib.h>
#include "rod_cut.h"
#include "cache.h"

#define MAX_INPUT_LINES 100

void read_pieces(const char *filename, Piece *pieces, int *num_pieces) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }
    *num_pieces = 0;
    while (fscanf(file, "%d, %d", &pieces[*num_pieces].length, &pieces[*num_pieces].value) == 2) {
        (*num_pieces)++;
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return 1;
    }
    
    Piece pieces[MAX_INPUT_LINES];
    int num_pieces;
    read_pieces(argv[1], pieces, &num_pieces);
    
    initialize_cache();
    
    int rod_length;
    while (scanf("%d", &rod_length) == 1) {
        int total_value;
        int cut_counts[MAX_INPUT_LINES] = {0};
        int remaining_length;
        
        if (get_from_cache(rod_length, &total_value, cut_counts, &remaining_length)) {
            printf("(Cached)\n");
        } else {
            calculate_cutting_plan(pieces, num_pieces, rod_length, cut_counts, &total_value, &remaining_length);
            add_to_cache(rod_length, total_value, cut_counts, remaining_length);
        }
        print_cutting_plan(pieces, num_pieces, cut_counts, remaining_length, total_value);
    }
    
    return 0;
}
