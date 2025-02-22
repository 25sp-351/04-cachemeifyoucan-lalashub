#include "rod_cut.h"
#include <stdio.h>
#include <stdlib.h>

void calculate_cutting_plan(Piece *pieces, int num_pieces, int supplied_length, int *cut_counts, int *total_value, int *remaining_length) {
    int dp[supplied_length + 1];
    int piece_choice[supplied_length + 1];

    for (int i = 0; i <= supplied_length; i++) {
        dp[i] = 0;
        piece_choice[i] = -1;
    }

    for (int i = 0; i <= supplied_length; i++) {
        for (int j = 0; j < num_pieces; j++) {
            if (pieces[j].length <= i) {
                int new_value = dp[i - pieces[j].length] + pieces[j].value;
                if (new_value > dp[i]) {
                    dp[i] = new_value;
                    piece_choice[i] = j;
                }
            }
        }
    }

    *total_value = dp[supplied_length];
    *remaining_length = supplied_length;

    while (piece_choice[*remaining_length] != -1) {
        int idx = piece_choice[*remaining_length];
        cut_counts[idx]++;
        *remaining_length -= pieces[idx].length;
    }
}


void print_cutting_plan(Piece *pieces, int num_pieces, int *cut_counts, int remaining_length, int total_value) {
    for (int ix = 0; ix < num_pieces; ix++) {
        if (cut_counts[ix] > 0) {
            printf("%d @ %d = %d\n", cut_counts[ix], pieces[ix].length, cut_counts[ix] * pieces[ix].value);
        }
    }
    printf("Remainder: %d\n", remaining_length);
    printf("Value: %d\n", total_value);
}