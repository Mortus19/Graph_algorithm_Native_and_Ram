#include "DSU.h"
#include <set>
#include <fstream>
#include <chrono>
#include <random>


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
        cur.u--;
        cur.v--;
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
    void resize(int _n = 0);
    int get_count_vertex();
    void add_edge(int x, int y);

    vector<int> Native_Algorithm_connectivity_component();

    vector<int> Ram_Algorithm_connectivity_component();

    bool is_connectivy();

    friend ostream &operator<<(ostream &out, const Graph &x);

    friend istream &operator>>(istream &in, Graph &x);
};

void generate_graph(int n, int m, const string &namefile);

void time_recording_for_Native(const string &input, const string &output);

void time_recording_for_Ram(const string &input, const string &output);