#ifndef SORTING_LIB_H
#define SORTING_LIB_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../utils/reader.h"

void merge_sort_rec(int * arr, int n);
void merge_rec(int * arr, int n, int i);

void merge_sort_iter(int * arr, int n);
void merge_iter(int * arr, int l, int m, int r);

void insertion_sort_iter(int * arr, int n);

void insertion_sort_rec(int * arr, int n);
void insertion_sort_rec_helper(int * arr, int n, int i);
int insertion_sort_rec_helper_helper(int * arr, int n, int j, int placeholder);



#endif
