#include <iostream>
#include <vector>
#include <set>

using namespace std;

class DSU {
    //disjoint-set-union
    int size;
    vector<int> root;
public:
    DSU(int _size = 0);

    DSU(const DSU &x);

    DSU &operator=(const DSU &x);

    void clear();

    int get(int x);

    void merge(int a, int b);

    friend ostream &operator<<(ostream &out, const DSU &x);
};
