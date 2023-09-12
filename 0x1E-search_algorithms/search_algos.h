#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdio.h>
#include <math.h>
#include <stddef.h>

/* Function prototypes */
int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int binary_search_exp(int *array, int l, int r, int value);
void print_array_bs_exp(int *array, int l, int r);
int advanced_binary(int *array, size_t size, int value);

#endif /* SEARCH_ALGOS_H */
