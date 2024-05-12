#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int node, int color, vector<int>& colors, vector<vector<int>>& graph, int N) {
    for (int i = 0; i < N; i++) {
        if (graph[node][i] && color == colors[i]) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int node, int M, vector<int>& colors, vector<vector<int>>& graph, int N) {
    if (node == N) {
        return true;
    }

    for (int color = 1; color <= M; color++) {
        if (isSafe(node, color, colors, graph, N)) {
            colors[node] = color;
            if (graphColoringUtil(node + 1, M, colors, graph, N)) {
                return true;
            }
            colors[node] = 0; // Backtrack
        }
    }

    return false;
}

bool graphColoring(vector<vector<int>>& graph, int M, int N) {
    vector<int> colors(N, 0);

    if (!graphColoringUtil(0, M, colors, graph, N)) {
        return false;
    }

    return true;
}

int main() {
    int N = 4; // Number of vertices
    int M = 3; // Number of colors
    int E = 5; // Number of edges

    // Example 1: Graph with 4 vertices and 5 edges
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2}};

    // Create adjacency matrix representation of the graph
    vector<vector<int>> graph(N, vector<int>(N, 0));
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u][v] = graph[v][u] = 1; // Mark edge between u and v
    }

    // Check if graph can be colored with M colors
    if (graphColoring(graph, M, N)) {
        cout << "1\n"; // Output: 1
    } else {
        cout << "0\n"; // Output: 0
    }

    return 0;
}
