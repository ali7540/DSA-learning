#include <bits/stdc++.h>

using namespace std;

// Dijkstra's algorithm using priority_queue (min-heap)
// Graph represented as adjacency list: vector of (neighbor, weight) pairs

vector<long long> dijkstra(int V, const vector<vector<pair<int,int>>> &adj, int src) {
	const long long INF = LLONG_MAX / 4;
	vector<long long> dist(V, INF);
	dist[src] = 0;

	// priority_queue of (distance, node)
	priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
	pq.push({0, src});

	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (d != dist[u]) continue; // stale entry

		for (auto &edge : adj[u]) {
			int v = edge.first;
			int w = edge.second;
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}

	return dist;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int V = 9;
	vector<vector<pair<int,int>>> adj(V);

	auto add_edge = [&](int u, int v, int w) {
		adj[u].push_back({v, w});
	};

	add_edge(0, 1, 4);
	add_edge(0, 7, 8);
	add_edge(1, 2, 8);
	add_edge(1, 7, 11);
	add_edge(2, 3, 7);
	add_edge(2, 8, 2);
	add_edge(2, 5, 4);
	add_edge(3, 4, 9);
	add_edge(3, 5, 14);
	add_edge(4, 5, 10);
	add_edge(5, 6, 2);
	add_edge(6, 7, 1);
	add_edge(6, 8, 6);
	add_edge(7, 8, 7);

	int src = 0;
	vector<long long> dist = dijkstra(V, adj, src);

	cout << "Vertex   Distance from Source (" << src << ")\n";
	// dijkstras.cpp - minimal, clean Dijkstra implementation
	#include <iostream>
	#include <vector>
	#include <queue>
	#include <limits>
	#include <iomanip>

	using namespace std;

	vector<long long> dijkstra(int V, const vector<vector<pair<int,int>>> &adj, int src) {
		const long long INF = numeric_limits<long long>::max() / 4;
		vector<long long> dist(V, INF);
		dist[src] = 0;

		priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
		pq.push({0, src});

		while (!pq.empty()) {
			auto cur = pq.top(); pq.pop();
			long long d = cur.first; int u = cur.second;
			if (d != dist[u]) continue;
			for (auto &e : adj[u]){
				int v = e.first, w = e.second;
				if (dist[u] + w < dist[v]){
					dist[v] = dist[u] + w;
					pq.push({dist[v], v});
				}
			}
		}
		return dist;
	}

	int main(){
		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		int V = 9;
		vector<vector<pair<int,int>>> adj(V);
		auto add = [&](int u,int v,int w){ adj[u].push_back({v,w}); };

		add(0,1,4); add(0,7,8);
		add(1,2,8); add(1,7,11);
		add(2,3,7); add(2,8,2); add(2,5,4);
		add(3,4,9); add(3,5,14);
		add(4,5,10);
		add(5,6,2);
		add(6,7,1); add(6,8,6);
		add(7,8,7);

		int src = 0;
		auto dist = dijkstra(V, adj, src);
		cout << "Vertex Distance from " << src << "\n";
		for (int i=0;i<V;++i){
			cout << setw(2) << i << " : ";
			if (dist[i] >= numeric_limits<long long>::max() / 8) cout << "INF";
			else cout << dist[i];
			cout << '\n';
		}
		return 0;
	}

