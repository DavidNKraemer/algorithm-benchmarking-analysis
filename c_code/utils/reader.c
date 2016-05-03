#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int read_in_sort_data(const char * infile_name, void(*sort_pointer)(double *, int));

int main(void) {
    void * fptr;
    read_in_sort_data("../../data/input_data/sorting_data.csv", fptr);
    return 0;
}

int read_in_sort_data(const char * infile_name, void(*sort_pointer)(double *, int)) {
    FILE *input_file;
    const char * delim = ",";
    input_file = fopen(infile_name, "r");

    if (input_file == NULL) {
        fprintf(stderr, "Can't open input file %s!\n",infile_name);
        exit(1);
    }

    char * buffer = NULL;
    char * token = NULL;
    char * token_end;
    int inner_count;
    int array_size = 0;
    int * array;
    size_t buffer_size;
    while ( !(feof(input_file)) ) {
        getline(&buffer, &buffer_size, input_file);
        inner_count = 0;
        while ( (token = strsep(&buffer, delim)) != NULL) {
            if (inner_count == 0) {
                array_size = strtol(token, &token_end, 10);
                printf("%d\n",array_size);
                array = malloc(array_size * sizeof(int));
            }
            else {
                array[inner_count - 1] = strtol(token, &token_end, 10);
            }
            inner_count++;
        }
        // do analysis here
        // time start
        // sort_pointer(array, array_size);
        // time end
        // record
        free(array);
    }

    fclose(input_file);
    return 1;

    

}
