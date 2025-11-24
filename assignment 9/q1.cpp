#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge {
    int src, dest, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};

class Graph {
    int V; 
    vector<vector<pair<int, int>>> adjList; 
    vector<Edge> edges; 
    
public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }
    
    void addEdge(int src, int dest, int weight) {
        adjList[src].push_back({dest, weight});
        adjList[dest].push_back({src, weight});
        edges.push_back({src, dest, weight});
    }
    
    void addDirectedEdge(int src, int dest, int weight) {
        adjList[src].push_back({dest, weight});
    }
    
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        
        visited[start] = true;
        q.push(start);
        
        cout << "BFS Traversal starting from vertex " << start << ": ";
        
        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            cout << vertex << " ";
            
            for (auto& neighbor : adjList[vertex]) {
                int v = neighbor.first;
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
    
    void DFSUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";
        
        for (auto& neighbor : adjList[vertex]) {
            int v = neighbor.first;
            if (!visited[v]) {
                DFSUtil(v, visited);
            }
        }
    }
    
    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal starting from vertex " << start << ": ";
        DFSUtil(start, visited);
        cout << endl;
    }
    
    void kruskalMST() {
        vector<Edge> result;
        sort(edges.begin(), edges.end());
        
        DisjointSet ds(V);
        int totalWeight = 0;
        
        for (Edge& edge : edges) {
            int x = ds.find(edge.src);
            int y = ds.find(edge.dest);
            
            if (x != y) {
                result.push_back(edge);
                totalWeight += edge.weight;
                ds.unite(x, y);
            }
        }
        
        cout << "\nKruskal's MST Edges:\n";
        for (Edge& edge : result) {
            cout << edge.src << " -- " << edge.dest << " (weight: " << edge.weight << ")\n";
        }
        cout << "Total MST Weight: " << totalWeight << endl;
    }
    
    void primMST() {
        vector<int> key(V, INT_MAX);     
        vector<bool> inMST(V, false);    
        vector<int> parent(V, -1);       
        
        key[0] = 0;
        
        for (int count = 0; count < V - 1; count++) {
            int minKey = INT_MAX, u = -1;
            for (int v = 0; v < V; v++) {
                if (!inMST[v] && key[v] < minKey) {
                    minKey = key[v];
                    u = v;
                }
            }
            
            inMST[u] = true;
        
            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                
                if (!inMST[v] && weight < key[v]) {
                    parent[v] = u;
                    key[v] = weight;
                }
            }
        }
        
        cout << "\nPrim's MST Edges:\n";
        int totalWeight = 0;
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " -- " << i << " (weight: " << key[i] << ")\n";
            totalWeight += key[i];
        }
        cout << "Total MST Weight: " << totalWeight << endl;
    }
    
    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        
        dist[src] = 0;
        
        for (int count = 0; count < V - 1; count++) {
            int minDist = INT_MAX, u = -1;
            for (int v = 0; v < V; v++) {
                if (!visited[v] && dist[v] < minDist) {
                    minDist = dist[v];
                    u = v;
                }
            }
            
            if (u == -1) break;
            visited[u] = true;
            
            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                
                if (!visited[v] && dist[u] != INT_MAX && 
                    dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                }
            }
        }
        
        cout << "\nDijkstra's Shortest Path from vertex " << src << ":\n";
        cout << "Vertex\tDistance\tPath\n";
        for (int i = 0; i < V; i++) {
            cout << i << "\t\t" << (dist[i] == INT_MAX ? -1 : dist[i]) << "\t\t\t";
            
            if (dist[i] != INT_MAX) {
                vector<int> path;
                int current = i;
                while (current != -1) {
                    path.push_back(current);
                    current = parent[current];
                }
                reverse(path.begin(), path.end());
                for (int j = 0; j < path.size(); j++) {
                    cout << path[j];
                    if (j < path.size() - 1) cout << " -> ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int V, E, choice;
    
    cout << "Enter number of vertices: ";
    cin >> V;
    
    Graph g(V);
    
    cout << "Enter number of edges: ";
    cin >> E;
    
    cout << "Enter edges (src dest weight):\n";
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        g.addEdge(src, dest, weight);
    }
    
    do {
        cout << "\n===== Graph Algorithms Menu =====\n";
        cout << "1. Breadth First Search (BFS)\n";
        cout << "2. Depth First Search (DFS)\n";
        cout << "3. Minimum Spanning Tree - Kruskal's Algorithm\n";
        cout << "4. Minimum Spanning Tree - Prim's Algorithm\n";
        cout << "5. Dijkstra's Shortest Path Algorithm\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                int start;
                cout << "Enter starting vertex for BFS: ";
                cin >> start;
                g.BFS(start);
                break;
            }
            case 2: {
                int start;
                cout << "Enter starting vertex for DFS: ";
                cin >> start;
                g.DFS(start);
                break;
            }
            case 3:
                g.kruskalMST();
                break;
            case 4:
                g.primMST();
                break;
            case 5: {
                int src;
                cout << "Enter source vertex for Dijkstra's: ";
                cin >> src;
                g.dijkstra(src);
                break;
            }
        }
    } while(choice != 0);
    
    return 0;
}
