#ifndef READER_H
#define READER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int analyze_sort_data(const char * infile_name, 
                      const char * outfile_name,
                      void (*sort_pointer)(int *, int));

int analyze_search_data(const char * infile_name, 
                        const char * outfile_name,
                        int (*search_pointer)(int *, int, int));

void print_array(int * array, int size);
#endif
