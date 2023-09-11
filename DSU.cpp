#include "DSU.h"

DSU::DSU(int _size) {
    size = _size;
    root.resize(size);
    for (int i = 0; i < size; i++) {
        root[i] = i;
    }
}

DSU::DSU(const DSU &x) {
    size = x.size;
    root = x.root;
}

DSU &DSU::operator=(const DSU &x) {
    if(this == &x) return *this;
    this->clear();
    size = x.size;
    root = x.root;
    return *this;
}

void DSU::clear() {
    size = 0;
    root.clear();
}

int DSU::get(int x) {
    int y = x;
    vector<int> values;
    while (y != root[y]) {
        values.push_back(y);
        y = root[y];
    }
    for (auto t: values)
        root[t] = y;
    return y;
}

void DSU::merge(int a, int b) {
    int x = get(a);
    int y = get(b);
    if (x != y) {
        root[y] = x;
    }
}

ostream &operator<<(ostream &out, const DSU &x) {
    out << "Size: " << x.size << '\n';
    for (int i = 0; i < x.size; i++) {
        out << "vertex " << i + 1 << " in set " << x.root[i] + 1 << '\n';
    }
    return out;
}