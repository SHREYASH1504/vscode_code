#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
    int V; 
    vector<vector<int>> adj; 

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v); 
    }   

    void BFS(int start) {
        vector<bool> visited(V, false); 
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS starting from vertex " << start << ": ";

        while (!q.empty()) {
            int node = q.front();
            cout << node << " ";
            q.pop();

            for (int i : adj[node]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int i : adj[node]) {
            if (!visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false); 

        cout << "DFS starting from vertex " << start << ": ";
        DFSUtil(start, visited);
        cout << endl;
    } 
};

int main() {
    Graph g(9); 

    g.addEdge(1, 2);
    g.addEdge(1, 6);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 5);
    g.addEdge(6, 7);
    g.addEdge(6, 8);
    g.addEdge(7, 5);

    g.BFS(1); 
    g.DFS(1); 

    return 0;
}
