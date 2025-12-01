#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    vector<vector<pair<int,int>>> weightedAdj;
    int parent[100];

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
        weightedAdj.resize(V);
    }

    void addEdge(int u, int v, int w = 0, bool directed = false) {
        adj[u].push_back(v);
        weightedAdj[u].push_back({v, w});
        if (!directed) {
            adj[v].push_back(u);
            weightedAdj[v].push_back({u, w});
        }
    }

    void BFS(int start) {
        bool visited[100] = {false};
        queue<int> q;
        q.push(start);
        visited[start] = true;
        cout << "BFS: ";
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";
            for (int neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";
        for (int u : adj[v]) {
            if (!visited[u])
                DFSUtil(u, visited);
        }
    }

    void DFS(int start) {
        bool visited[100] = {false};
        cout << "DFS: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unionSets(int x, int y) {
        parent[find(x)] = find(y);
    }

    void Kruskal() {
        vector<pair<int, pair<int,int>>> edges;
        for (int u = 0; u < V; u++) {
            for (auto p : weightedAdj[u]) {
                int v = p.first;
                int w = p.second;
                if (u < v)
                    edges.push_back({w, {u, v}});
            }
        }
        sort(edges.begin(), edges.end());
        for (int i = 0; i < V; i++) parent[i] = i;

        cout << "Kruskal MST:\n";
        int cost = 0;
        for (auto e : edges) {
            int w = e.first;
            int u = e.second.first;
            int v = e.second.second;
            if (find(u) != find(v)) {
                unionSets(u, v);
                cout << u << " - " << v << " = " << w << endl;
                cost += w;
            }
        }
        cout << "Total = " << cost << endl;
    }

    void Prim(int start = 0) {
        vector<int> key(V, 99999);
        vector<int> par(V, -1);
        vector<bool> inMST(V, false);
        key[start] = 0;

        for (int count = 0; count < V; count++) {
            int mini = 99999, u = -1;
            for (int i = 0; i < V; i++) {
                if (!inMST[i] && key[i] < mini) {
                    mini = key[i];
                    u = i;
                }
            }
            if (u == -1) break;
            inMST[u] = true;
            for (auto p : weightedAdj[u]) {
                int v = p.first;
                int weight = p.second;
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    par[v] = u;
                }
            }
        }

        cout << "Prim MST:\n";
        int total = 0;
        for (int i = 0; i < V; i++) {
            if (par[i] != -1) {
                cout << par[i] << " - " << i << " = " << key[i] << endl;
                total += key[i];
            }
        }
        cout << "Total = " << total << endl;
    }

    void Dijkstra(int src) {
        vector<int> dist(V, 99999);
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (d > dist[u]) continue;
            for (auto p : weightedAdj[u]) {
                int v = p.first;
                int w = p.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Dijkstra from " << src << ":\n";
        for (int i = 0; i < V; i++) {
            cout << i << " -> " << dist[i] << endl;
        }
    }
};

int main() {
    Graph g(6);

    g.addEdge(0,1,4);
    g.addEdge(0,2,8);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,4,5);
    g.addEdge(3,4,3);
    g.addEdge(3,5,1);
    g.addEdge(4,5,7);

    g.BFS(0);
    cout << endl;
    g.DFS(0);
    cout << endl;
    g.Kruskal();
    cout << endl;
    g.Prim(0);
    cout << endl;
    g.Dijkstra(0);

    return 0;
}