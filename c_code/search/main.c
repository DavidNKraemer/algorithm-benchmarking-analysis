#include "searchlib.h"
int (*search_ptrs[4]) (int * arr, int size, int query) = { linear_search_rec,
    linear_search_iter,
    binary_search_rec,
    binary_search_iter };

const char *search_names[4] = { "linear_recursive",
    "linear_iterative",
    "binary_recursive",
    "binary_iterative" };


int main(int argc, char ** argv) {
    const char * input_source = "../../data/input_data/search_data.csv";
    char * output_source = "../../data/output_data/c_search.csv";
    if (safe_remove(output_source)) {
        printf("Overwriting existing file.\n");
    }
    else {
        printf("No existing file. Making a new one.\n");
    }

    FILE * header_writer = fopen(output_source, "a");
    fprintf(header_writer, "input,query,time,language,algorithm\n");
    fclose(header_writer);

    for (int i = 0; i < 4; i++) {
        analyze_search_data(input_source, output_source, search_ptrs[i], 
                search_names[i]);
    }

    return 0;
}
