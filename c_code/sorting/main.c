#include "sortlib.h"
void (*sort_ptrs[4]) (int * arr, int size) = { insertion_sort_rec,
    insertion_sort_iter,
    merge_sort_rec,
    merge_sort_iter };

const char *sort_names[4] = { "insertion_recursive",
    "insertion_iterative",
    "merge_recursive",
    "merge_iterative" };


int main(int argc, char ** argv) {
    const char * input_source = "../../data/input_data/sorting_data.csv";
    char * output_source = "../../data/output_data/c_sort.csv";
    for (int i = 0; i < 4; i++) {
        analyze_sort_data(input_source, output_source, sort_ptrs[i],
                sort_names[i])
    }

    return 0;
}
