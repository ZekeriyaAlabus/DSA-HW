#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValidMove(vector<vector<int>>& maze, vector<vector<bool>>& visited, int x, int y) {
    int n = maze.size();
    return x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && !visited[x][y];
}

void explorePaths(vector<vector<int>>& maze, vector<vector<bool>>& visited, int x, int y, int dest_x, int dest_y, string currentPath, vector<string>& paths) {
    if (x == dest_x && y == dest_y) {
        paths.push_back(currentPath);
        return;
    }

    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<char> directions = {'D', 'U', 'L', 'R'};

    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (isValidMove(maze, visited, new_x, new_y)) {
            visited[new_x][new_y] = true;
            explorePaths(maze, visited, new_x, new_y, dest_x, dest_y, currentPath + directions[i], paths);
            visited[new_x][new_y] = false;
        }
    }
}

vector<string> printPath(int N, vector<vector<int>>& m) {
    if (N < 2) {
        return {};
    }

    int source_x = 0, source_y = 0;
    int dest_x = N - 1, dest_y = N - 1;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<string> paths;

    if (m[source_x][source_y] == 1 && m[dest_x][dest_y] == 1) {
        visited[source_x][source_y] = true;
        explorePaths(m, visited, source_x, source_y, dest_x, dest_y, "", paths);
    }

    sort(paths.begin(), paths.end());
    return paths;
}

int main() {
    int N = 4;
    vector<vector<int>> m = {{1, 0, 0, 0},
                              {1, 1, 0, 1},
                              {1, 1, 0, 0},
                              {0, 1, 1, 1}};

    vector<string> result = printPath(N, m);
    for (const string& path : result) {
        cout << path << " ";
    }
    cout << endl;

    return 0;
}
