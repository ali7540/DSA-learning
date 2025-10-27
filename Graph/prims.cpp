#include <bits/stdc++.h>
using namespace std;

// Prim's algorithm for Minimum Spanning Tree (MST)
// Input: undirected weighted graph as adjacency list
// Output: total weight of MST and the edges chosen

pair<long long, vector<tuple<int,int,int>>> prims(int V, const vector<vector<pair<int,int>>> &adj, int src=0) {
    const long long INF = LLONG_MAX / 4;
    vector<long long> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    key[src] = 0;
    // min-heap of (key, vertex)
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [k, u] = pq.top(); pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;

        for (auto &e : adj[u]) {
            int v = e.first; int w = e.second;
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    long long total = 0;
    vector<tuple<int,int,int>> edges;
    for (int v = 0; v < V; ++v) {
        if (parent[v] != -1) {
            edges.emplace_back(parent[v], v, key[v]);
            total += key[v];
        }
    }

    return {total, edges};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V = 9;
    vector<vector<pair<int,int>>> adj(V);
    auto add_undirected = [&](int u, int v, int w) {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    };

    add_undirected(0,1,4);
    add_undirected(0,7,8);
    add_undirected(1,2,8);
    add_undirected(1,7,11);
    add_undirected(2,3,7);
    add_undirected(2,8,2);
    add_undirected(2,5,4);
    add_undirected(3,4,9);
    add_undirected(3,5,14);
    add_undirected(4,5,10);
    add_undirected(5,6,2);
    add_undirected(6,7,1);
    add_undirected(6,8,6);
    add_undirected(7,8,7);

    auto [total, edges] = prims(V, adj, 0);
    cout << "Prim's MST total weight: " << total << "\n";
    cout << "Edges in MST:\n";
    for (auto &t : edges) {
        int u,v,w; tie(u,v,w) = t;
        cout << u << " - " << v << " (" << w << ")\n";
    }

    return 0;
}
