#include <set>
#include "DSU.h"


struct Edge {
    int u, v;

    Edge(int _u = 0, int _v = 0) {
        if (u > v) swap(u, v);
        u = _u;
        v = _v;
    }

    friend ostream &operator<<(ostream &out, const Edge &cur) {
        out << "(" << cur.u << "," << cur.v << ")\n";
        return out;
    }

    friend istream &operator>>(istream &in, Edge &cur) {
        in >> cur.u >> cur.v;
        if (cur.u > cur.v) swap(cur.u, cur.v);
        return in;
    }
};

class Graph {
    int n;
    vector<Edge> edges;
public:
    Graph(int _n = 0, const vector<Edge> &_edges = {});

    Graph(const Graph &x);

    Graph &operator=(const Graph &x);

    bool operator==(const Graph &x);

    bool operator!=(const Graph &x);

    void clear();

    vector<int> Native_Algorithm_connectivity_component();

    vector<int> Ram_Algorithm_connectivity_component();

    friend ostream &operator<<(ostream &out, const Graph &x);

    friend istream &operator>>(istream &in, Graph &x);
};

