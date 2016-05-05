#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

int analyze_sort_data(const char * infile_name, 
                      const char * outfile_name,
                      void (*sort_pointer)(int *, int),
                      const char * sort_name);

int analyze_search_data(const char * infile_name, 
                        const char * outfile_name,
                        int (*search_pointer)(int *, int, int),
                        const char * search_name);

void print_array(int * array, int size);

int safe_remove(const char * filename);
#endif
