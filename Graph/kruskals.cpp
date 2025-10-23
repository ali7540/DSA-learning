#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> p, r;
    DSU(int n): n(n), p(n), r(n,0) { iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b){
        a=find(a); b=find(b); if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a; if(r[a]==r[b]) r[a]++;
        return true;
    }
};

// Kruskal's algorithm: edges list (u,v,w), returns MST total weight and chosen edges
pair<long long, vector<tuple<int,int,int>>> kruskals(int V, vector<tuple<int,int,int>> edges) {
    sort(edges.begin(), edges.end(), [](const auto &a, const auto &b){ return get<2>(a) < get<2>(b); });
    DSU dsu(V);
    long long total = 0;
    vector<tuple<int,int,int>> mst;
    for (auto &e : edges) {
        int u,v,w; tie(u,v,w) = e;
        if (dsu.unite(u,v)) {
            total += w;
            mst.emplace_back(u,v,w);
        }
    }
    return {total, mst};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V = 9;
    vector<tuple<int,int,int>> edges;
    auto add = [&](int u,int v,int w){ edges.emplace_back(u,v,w); };

    add(0,1,4);
    add(0,7,8);
    add(1,2,8);
    add(1,7,11);
    add(2,3,7);
    add(2,8,2);
    add(2,5,4);
    add(3,4,9);
    add(3,5,14);
    add(4,5,10);
    add(5,6,2);
    add(6,7,1);
    add(6,8,6);
    add(7,8,7);

    auto [total, mst] = kruskals(V, edges);
    cout << "Kruskal's MST total weight: " << total << "\n";
    cout << "Edges in MST:\n";
    for (auto &t : mst) {
        int u,v,w; tie(u,v,w) = t;
        cout << u << " - " << v << " (" << w << ")\n";
    }

    return 0;
}
