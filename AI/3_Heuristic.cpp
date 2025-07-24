#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

const int INF = 999;
const int N = 9;

int adjmatrix[N][N];
int heuristic[N];
bool visited[N];
int dist[N];
int parent[N]; // To store the path

void initialize_graph()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            adjmatrix[i][j] = INF;
        }
        heuristic[i] = 0;
        visited[i] = false;
        dist[i] = INF;
        parent[i] = -1; // No parent initially
    }
}

// Function to add edges between nodes
void add_edge(int u, int v, int weight)
{
    adjmatrix[u][v] = weight;
    adjmatrix[v][u] = weight;
}

// Function to set heuristic values
void set_heuristic(int heuristic_values[])
{
    for (int i = 0; i < N; i++)
    {
        heuristic[i] = heuristic_values[i];
    }
}

// A* algorithm implementation
void a_star_algorithm(int goal)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[0] = 0;
    pq.push(make_pair(dist[0] + heuristic[0], 0));

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        if (u == goal)
            return;

        for (int v = 0; v < N; v++)
        {
            if (!visited[v] && adjmatrix[u][v] != INF)
            {
                int tentative_g_score = dist[u] + adjmatrix[u][v];
                if (tentative_g_score < dist[v])
                {
                    dist[v] = tentative_g_score;
                    parent[v] = u; // Store the parent to reconstruct the path
                    pq.push(make_pair(dist[v] + heuristic[v], v));
                }
            }
        }
    }
}

// Function to reconstruct the path from the goal node
void reconstruct_path(int goal)
{
    vector<int> path;
    for (int v = goal; v != -1; v = parent[v])
    {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    cout << "Path to goal node " << goal << " : ";
    for (int node : path)
    {
        cout << node << " ";
    }
    cout << endl;
}

int main()
{
    // Initialize the graph
    initialize_graph();

    // Add edges to the graph
    add_edge(0, 1, 3);
    add_edge(0, 3, 2);
    add_edge(1, 2, 1);
    add_edge(1, 4, 4);
    add_edge(2, 5, 5);
    add_edge(2, 6, 3);
    add_edge(3, 4, 6);
    add_edge(3, 7, 7);
    add_edge(4, 5, 2);
    add_edge(5, 6, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 3);

    // Set heuristic values (estimated distance to the goal node 6)
    int heuristic_values[N] = {10, 8, 5, 7, 6, 3, 0, 9, 7};
    set_heuristic(heuristic_values);

    // Define the goal node
    int goal = 6;

    // Execute the A* algorithm
    a_star_algorithm(goal);

    // Output the path
    reconstruct_path(goal);

    return 0;
}
