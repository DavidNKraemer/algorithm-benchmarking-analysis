#include "reader.h"

void print_array(int * array, int size) {
    printf("[");
    for (int i = 0; i < size-1; i ++) {
        printf("%d,", array[i]);
    }
    printf("%d]\n",array[size-1]);
}

int analyze_sort_data(const char * infile_name, 
        const char * outfile_name,
        void (*sort_pointer)(int *, int),
        const char * sort_name) {

    // Open file ports
    FILE *input_file, *output_file;

    printf("Reading from \"%s\"...", infile_name);
    input_file = fopen(infile_name, "r");

    // Verifies that input_file and output_file successfully opened file ports
    if (input_file == NULL) {
        fprintf(stderr, "\nCan't open input file %s!\n",infile_name);
        exit(1);
    }
    printf(" done.\n");

    printf("Writing to \"%s\"...\n", outfile_name);
    output_file = fopen(outfile_name, "a");

    if (output_file == NULL) {
        fprintf(stderr, "\nCan't open output file %s!\n", outfile_name);
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
    struct timeval start, end;
    long int difference;



    // Loop through the lines of the input file
    printf("\t");
    while ( !(feof(input_file)) ) {
        printf("*");

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
        gettimeofday(&start, NULL);
        sort_pointer(array, array_size);
        gettimeofday(&end, NULL);
        difference = end.tv_usec - start.tv_usec;

        //print_array(array, array_size);
        // Record to the output file
        fprintf(output_file, "%d, %ld\n", array_size, difference);

        // Free the array. Rinse and repeat.
        free(array);
    }
    printf(" done.\n");

    // Close file ports
    fclose(input_file);
    fclose(output_file);

    return 1;
}

int analyze_search_data(const char * infile_name, 
        const char * outfile_name,
        int (*search_pointer)(int *, int, int),
        const char * search_name);

    // Open file ports
    FILE *input_file, *output_file;
    printf("Reading from \"%s\"...", infile_name);
    input_file = fopen(infile_name, "r");

    // Verifies that input_file and output_file successfully opened file ports
    if (input_file == NULL) {
        fprintf(stderr, "Can't open input file %s!\n",infile_name);
        exit(1);
    }

    printf(" done.\n");

    printf("Writing to \"%s\"...\n", outfile_name);
    output_file = fopen(outfile_name, "a");
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
    struct timeval start, end;
    long int difference;


    printf("\t");
    // Loop through the lines of the input file
    while ( !(feof(input_file)) ) {
        printf("*");

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

        //print_array(array, array_size);

        // After acquiring all of the data for a given array, measure the 
        // sorting time
        gettimeofday(&start, NULL);
        result = search_pointer(array, array_size, result);
        gettimeofday(&end, NULL);
        difference = end.tv_usec - start.tv_usec;

        // Record to the output file
        fprintf(output_file, "%d, %d, %ld\n", array_size, result, difference);

        // Free the array. Rinse and repeat.
        free(array);
    }
    printf(" done.\n");

    // Close file ports
    fclose(input_file);
    fclose(output_file);

    return 1;
}
