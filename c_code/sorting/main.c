#include "sortlib.h"
int main(int argc, char ** argv) {
    void (*merge_sort_ptr) = merge_sort_rec;
    const char * input_source = "../../data/input_data/sorting_data.csv";
    const char * output_source = "../../data/output_data/c_data/msr.csv";
    analyze_sort_data(input_source, output_source, merge_sort_ptr);

    return 0;
}
