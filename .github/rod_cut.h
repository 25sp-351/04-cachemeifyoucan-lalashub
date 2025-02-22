#ifndef ROD_CUT_H
#define ROD_CUT_H

typedef struct {
    int length;
    int value;
} Piece;

void calculate_cutting_plan(Piece *pieces, int num_pieces, int supplied_length, int *cut_counts, int *total_value, int *remaining_length);
void print_cutting_plan(Piece *pieces, int num_pieces, int *cut_counts, int remaining_length, int total_value);

#endif