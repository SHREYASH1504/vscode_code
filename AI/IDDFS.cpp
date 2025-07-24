#include <iostream>
#include <vector>
using namespace std;

class IterativeDeepeningDFS {
private:
    vector<vector<int>> adjacencyMatrix;
    int numberOfVertices;

    bool depthLimitedDFS(int currentVertex, int targetVertex, int depthLimit, vector<bool> &visited) {
        cout << "Checking vertex " << currentVertex << " with depth limit " << depthLimit << endl;
        if (currentVertex == targetVertex) {
            return true;
        }
        if (depthLimit <= 0) {
            return false;
        }

        visited[currentVertex] = true;

        // Recur for all adjacent vertices
        for (int i = 0; i < numberOfVertices; i++) {
            if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                cout << "Moving to vertex " << i << endl;
                if (depthLimitedDFS(i, targetVertex, depthLimit - 1, visited)) {
                    return true;
                }
            }
        }
        return false; // Target vertex not found
    }

public:
    IterativeDeepeningDFS(const vector<vector<int>> &matrix) : adjacencyMatrix(matrix) {
        numberOfVertices = matrix.size();
    }

    void IDDFS(int startVertex, int targetVertex) {
        for (int depth = 0; depth < numberOfVertices; depth++) {
            vector<bool> visited(numberOfVertices, false);
            cout << "Searching at depth: " << depth << endl;

            if (depthLimitedDFS(startVertex, targetVertex, depth, visited)) {
                cout << "Target vertex " << targetVertex << " found at depth: " << depth << endl;
                return;
            }
        }

        cout << "Target vertex " << targetVertex << " not found within the maximum depth." << endl;
    }
};

int main() {
    vector<vector<int>> adjacencyMatrix = {
        {0, 1, 1, 0, 0, 0},  
        {1, 0, 0, 1, 0, 0},  
        {1, 0, 0, 0, 1, 0},  
        {0, 1, 0, 0, 1, 1}, 
        {0, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 0}
    };

    int startVertex, targetVertex;
    cout << "Please enter the start vertex: ";
    cin >> startVertex;
    cout << "Please enter the goal vertex: ";
    cin >> targetVertex;

    IterativeDeepeningDFS iddfs(adjacencyMatrix);
    iddfs.IDDFS(startVertex, targetVertex);

    return 0;
}

