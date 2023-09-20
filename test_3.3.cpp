#include "Graph.h"

int main() {
    string input = "input_test_3_3.txt";
    string output_Ram = "output_test_3_3_Ram.txt";
    string output_Native = "output_test_3_3_Native.txt";
    for (int n = 1; n <= 1000 + 1; n += 10) {
        int m = (int) log2(n);
        generate_graph(n, m, input);
        for (int j = 0; j < 5; j++) {
            time_recording_for_Ram(n, input, output_Ram);
            time_recording_for_Native(n, input, output_Native);
        }
    }
    return 0;
}