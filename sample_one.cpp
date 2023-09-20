#include "Graph.h"


int main() {

    int n = 5;
    Graph g(n);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 4);

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
