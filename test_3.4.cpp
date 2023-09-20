#include "Graph.h"

void test(int n , const string& output){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ofstream out;
    out.open(output,std::ios_base::app);
    Graph g(n);
    int maxsize = n * (n - 1) / 2;
    vector<pair<int, int>> edges(maxsize);
    vector<int> was(maxsize, 0);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges[cur] = {i, j};
            cur++;
        }
    }
    for(int i = 0;i<n-1;i++){
        int id = rng() % maxsize;
        while (was[id] == 1) {
            id = rng() % maxsize;
        }
        was[id] = 1;
        g.add_edge(edges[id].first,edges[id].second);
    }
    int m = n-1;
    while(!g.is_connectivy()){
        int id = rng() % maxsize;
        while (was[id] == 1) {
            id = rng() % maxsize;
        }
        was[id] = 1;
        g.add_edge(edges[id].first,edges[id].second);
        m++;
    }
    out<<n<<' '<<m<<'\n';
    out.close();
}

int main(){
    string output = "output_test_3_4.txt";
    for(int n = 1;n<=1000+1;n+=10){
        cout<<n<<'\n';
        for(int j = 0;j<5;j++){
            test(n,output);
        }
    }
    return 0;
}