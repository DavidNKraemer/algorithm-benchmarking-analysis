#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int read_in_data(const char * infile_name);

int main(void) {
    read_in_data("../../data/input_data/sorting_data.csv");
    return 0;
}

int read_in_data(const char * infile_name) {
    FILE *input_file;
    const char * delim = ",";
    input_file = fopen(infile_name, "r");

    if (input_file == NULL) {
        fprintf(stderr, "Can't open input file %s!\n",infile_name);
        exit(1);
    }

    char * buffer;
    char * token;
    size_t buffer_size;
    while ( !(feof(input_file)) ) {
        getline(&buffer, &buffer_size, input_file);
        while ( (token = strsep(&buffer, delim)) != NULL)
            printf("%s\n", token);
    }

    fclose(input_file);
    return 1;

    

}
