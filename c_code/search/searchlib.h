#ifndef SEARCH_LIB_H
#define SEARCH_LIB_H

#include "../utils/processor.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binary_search_iter(int * arr, int n, int value);
int binary_search_rec(int * arr, int n, int value);
int binary_search_rec_helper(int * arr, int low, int high, 
    int value);

int linear_search_iter(int * arr, int n, int value);
int linear_search_rec(int * arr, int n, int value);
int linear_search_rec_helper(int * arr, int index, int n, int value);

#endif
