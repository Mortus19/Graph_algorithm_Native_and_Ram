#include "Graph.h"


int main() {

    Graph g;
    cin >> g;
    int n = g.get_count_vertex();
    vector<int> comp_native = g.Native_Algorithm_connectivity_component();

    for (int i = 0; i < n; i++) {
        cout << "vertex " << i + 1 << " at component " << comp_native[i] + 1 << '\n';
    }

    vector<int> comp_Ram = g.Ram_Algorithm_connectivity_component();

    cout << "=================\n";

    for (int i = 0; i < n; i++) {
        cout << "vertex " << i + 1 << " at component " << comp_Ram[i] + 1 << '\n';
    }

    return 0;
}
