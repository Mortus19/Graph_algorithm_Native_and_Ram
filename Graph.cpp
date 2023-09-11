#include "Graph.h"

Graph::Graph(int _n, const vector<Edge> &_edges) {
    n = _n;
    edges = _edges;
}

Graph::Graph(const Graph &x) {
    n = x.n;
    edges = x.edges;
}

Graph &Graph::operator=(const Graph &x) {
    if (&x == this)
        return *this;
    this->clear();
    n = x.n;
    edges = x.edges;
    return *this;
}

bool Graph::operator==(const Graph &x) {
    if (this == &x) return true;
    if (n != x.n) return false;
    if (edges.size() != x.edges.size()) return false;
    set<pair<int, int>> s;
    for (int i = 0; i < edges.size(); i++) {
        s.insert({edges[i].u, edges[i].v});
    }
    for (int i = 0; i < x.edges.size(); i++) {
        pair<int, int> t = {x.edges[i].u, x.edges[i].v};
        if (s.count(t) == 0) return false;
    }
    return true;
}

bool Graph::operator!=(const Graph &x) {
    if (*this == x)
        return false;
    return true;
}

void Graph::clear() {
    n = 0;
    edges.clear();
}

vector<int> Graph::Native_Algorithm_connectivity_component() {
    vector<int> comp(n);
    for (int i = 0; i < n; i++) {
        comp[i] = i;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < edges.size(); j++) {
            int q = min(comp[edges[j].u], comp[edges[j].v]);
            comp[edges[j].u] = q;
            comp[edges[j].v] = q;
        }
    }
    return comp;
}

vector<int> Graph::Ram_Algorithm_connectivity_component() {
    vector<int> comp(n);
    for (int i = 0; i < n; i++) {
        comp[i] = i;
    }
    DSU dsu(n);
    for (int i = 0; i < edges.size(); i++) {
        int a = dsu.get(edges[i].u);
        int b = dsu.get(edges[i].v);
        if (a != b) {
            dsu.merge(a, b);
        }
    }
    for (int i = 0; i < n; i++) {
        comp[i] = dsu.get(i);
    }
    return comp;
}

ostream &operator<<(ostream &out, const Graph &x) {
    out << "vertex count: " << x.n << '\n';
    out << "Edges:\n";
    for (int i = 0; i < x.edges.size(); i++) {
        out << x.edges[i] << '\n';
    }
    return out;
}

istream &operator>>(istream &in, Graph &x) {
    x.clear();
    int m; // count of edges
    in >> x.n >> m;
    x.edges.resize(m);
    for (int i = 0; i < m; i++) {
        in >> x.edges[i];
    }
    return in;
}