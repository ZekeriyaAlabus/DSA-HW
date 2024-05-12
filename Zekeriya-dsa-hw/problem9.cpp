#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<string> dictionary;
vector<vector<bool>> visited;
vector<string> result;

bool isValid(int x, int y, int R, int C) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

void DFS(vector<vector<char>>& board, int x, int y, string prefix) {
    visited[x][y] = true;
    prefix += board[x][y];

    if (dictionary.find(prefix) != dictionary.end()) {
        result.push_back(prefix);
    }

    int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
    int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

    for (int k = 0; k < 8; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (isValid(nx, ny, board.size(), board[0].size()) && !visited[nx][ny]) {
            DFS(board, nx, ny, prefix);
        }
    }

    visited[x][y] = false; // Backtrack
}

vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& words) {
    result.clear();
    dictionary.clear();
    visited.clear();

    // Convert dictionary to set for faster lookup
    for (const string& word : words) {
        dictionary.insert(word);
    }

    int R = board.size();
    int C = board[0].size();
    visited.resize(R, vector<bool>(C, false));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            string prefix = "";
            DFS(board, i, j, prefix);
        }
    }

    return result;
}

int main() {
    int N1 = 1;
    vector<string> dictionary1 = {"CAT"};
    int R1 = 3, C1 = 3;
    vector<vector<char>> board1 = {{'C','A','P'},{'A','N','D'},{'T','I','E'}};

    vector<string> result1 = wordBoggle(board1, dictionary1);
    for (const string& word : result1) {
        cout << word << " ";
    }
    cout << endl;

    int N2 = 4;
    vector<string> dictionary2 = {"GEEKS","FOR","QUIZ","GO"};
    int R2 = 3, C2 = 3;
    vector<vector<char>> board2 = {{'G','I','Z'},{'U','E','K'},{'Q','S','E'}};

    vector<string> result2 = wordBoggle(board2, dictionary2);
    for (const string& word : result2) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
