#include "reader.h"

int analyze_sort_data(const char * infile_name, 
                      const char * outfile_name,
                      void (*sort_pointer)(int *, int)) {

    // Open file ports
    FILE *input_file, *output_file;
    input_file = fopen(infile_name, "r");
    output_file = fopen(outfile_name, "w+");

    // Verifies that input_file and output_file successfully opened file ports
    if (input_file == NULL) {
        fprintf(stderr, "Can't open input file %s!\n",infile_name);
        exit(1);
    }

    if (output_file == NULL) {
        fprintf(stderr, "Can't open output file %s!\n", outfile_name);
    }

    // Strings that are allocated for reading in the CSV
    char * buffer = NULL;
    char * token = NULL;
    char * token_end;
    const char * delim = ",";
    int inner_count;

    // Array to be sorted
    int array_size = 0;
    int * array;

    // Time information
    size_t buffer_size;
    time_t start, end;
    double difference;


    // Loop through the lines of the input file
    while ( !(feof(input_file)) ) {

        getline(&buffer, &buffer_size, input_file);
        inner_count = 0;

        // Loop through the entries on a given line
        while ( (token = strsep(&buffer, delim)) != NULL) {

            // The first entry gives the number of remaining entries
            if (inner_count == 0) {
                array_size = strtol(token, &token_end, 10);
                array = malloc(array_size * sizeof(int));
            }

            else {
                array[inner_count - 1] = strtol(token, &token_end, 10);
            }

            inner_count++;
        }

        // After acquiring all of the data for a given array, measure the 
        // sorting time
        time(&start);
        sort_pointer(array, array_size);
        time(&end);
        difference = difftime(end, start);

        // Record to the output file
        fprintf(output_file, "%d, %lf\n", array_size, difference);

        // Free the array. Rinse and repeat.
        free(array);
    }

    // Close file ports
    fclose(input_file);
    fclose(output_file);

    return 1;
}

int analyze_search_data(const char * infile_name, 
                        const char * outfile_name,
                        int (*search_pointer)(int *, int, int)) {

    // Open file ports
    FILE *input_file, *output_file;
    input_file = fopen(infile_name, "r");
    output_file = fopen(outfile_name, "w+");

    // Verifies that input_file and output_file successfully opened file ports
    if (input_file == NULL) {
        fprintf(stderr, "Can't open input file %s!\n",infile_name);
        exit(1);
    }

    if (output_file == NULL) {
        fprintf(stderr, "Can't open output file %s!\n", outfile_name);
        exit(1);
    }

    // Strings that are allocated for reading in the CSV
    char * buffer = NULL;
    char * token = NULL;
    char * token_end;
    const char * delim = ",";
    int inner_count;

    // Array to be sorted
    int array_size = 0;
    int * array;
    int result;

    // Time information
    size_t buffer_size;
    time_t start, end;
    double difference;


    // Loop through the lines of the input file
    while ( !(feof(input_file)) ) {

        getline(&buffer, &buffer_size, input_file);
        inner_count = 0;

        // Loop through the entries on a given line
        while ( (token = strsep(&buffer, delim)) != NULL) {

            // The first entry gives the number of remaining entries
            if (inner_count == 0) {
                result = strtol(token, &token_end, 10);
            }
            else if (inner_count == 1) {
                array_size = strtol(token, &token_end, 10);
                array = malloc(array_size * sizeof(int));
            }

            else {
                array[inner_count - 2] = strtol(token, &token_end, 10);
            }

            inner_count++;
        }

        // After acquiring all of the data for a given array, measure the 
        // sorting time
        time(&start);
        result = search_pointer(array, array_size, result);
        time(&end);
        difference = difftime(end, start);

        // Record to the output file
        fprintf(output_file, "%d, %d, %lf\n", array_size, result, difference);

        // Free the array. Rinse and repeat.
        free(array);
    }

    // Close file ports
    fclose(input_file);
    fclose(output_file);

    return 1;
}
