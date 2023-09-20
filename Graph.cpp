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

void Graph::add_edge(int x, int y) {
    edges.push_back(Edge(x, y));
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

bool Graph::is_connectivy() {
    vector<int> comp = Ram_Algorithm_connectivity_component();
    if (count(comp.begin(), comp.end(), comp[0]) == n) {
        return true;
    }
    return false;
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

void generate_graph(int n, int m, const string &namefile) {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ofstream out;
    out.open(namefile);
    int maxsize = n * (n - 1) / 2;
    vector<pair<int, int>> edges(maxsize);
    vector<int> was(maxsize, 0);
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            edges[cur] = {i, j};
            cur++;
        }
    }
    out << n << ' ' << m << '\n';
    for (int i = 0; i < m; i++) {
        int id = rng() % maxsize;
        while (was[id] == 1) {
            id = rng() % maxsize;
        }
        was[id] = 1;
        out << edges[id].first << ' ' << edges[id].second << '\n';
    }
    out.close();
}

void time_recording_for_Ram(int n, const string &input, const string &output) {
    Graph g;
    ifstream in;
    ofstream out;
    in.open(input);
    in >> g;
    in.close();
    out.open(output, std::ios_base::app);
    auto start = chrono::high_resolution_clock::now();
    vector<int> t = g.Ram_Algorithm_connectivity_component();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = (end - start);
    duration *= 1000.0 * 1000.0;// in mks
    out.precision(10);
    out << fixed << n << " " << duration.count() << '\n';
    out.close();

}

void time_recording_for_Native(int n, const string &input, const string &output) {
    Graph g;
    ifstream in;
    ofstream out;
    in.open(input);
    in >> g;
    in.close();
    out.open(output, std::ios_base::app);
    auto start = chrono::high_resolution_clock::now();
    vector<int> t = g.Native_Algorithm_connectivity_component();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = (end - start);
    duration *= 1000.0 * 1000.0;// in mks
    out.precision(10);
    out << fixed << n << " " << duration.count() << '\n';
    out.close();
}