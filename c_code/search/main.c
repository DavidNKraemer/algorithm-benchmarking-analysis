#include "searchlib.h"
int main(int argc, char ** argv) {
    void (*search_ptr) = binary_search_rec;
    const char * input_source = "../../data/input_data/search_data.csv";
    const char * output_source = "../../data/output_data/c_data/msr.csv";
    analyze_search_data(input_source, output_source, search_ptr);
    return 0;
}
