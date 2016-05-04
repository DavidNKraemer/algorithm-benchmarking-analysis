#include "searchlib.h"
int (*search_ptrs[4]) (int * arr, int size, int query) = { linear_search_rec,
    linear_search_iter,
    binary_search_rec,
    binary_search_iter };

const char *output_sources[4] = { "linear_recursive",
    "linear_iterative",
    "binary_recursive",
    "binary_iterative" };


int main(int argc, char ** argv) {
    const char * input_source = "../../data/input_data/search_data.csv";
    char output_source[80];
    for (int i = 0; i < 4; i++) {
        sprintf(output_source, "../../data/output_data/%s.csv",
                output_sources[i]);
        analyze_search_data(input_source, output_source, search_ptrs[i]);
    }

    return 0;
}
