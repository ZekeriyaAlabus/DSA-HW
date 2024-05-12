#include <iostream>
#include <vector>

using namespace std;

int numberSequence(int m, int n) {
    // Initialize DP table
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base case: for n = 1, there is only one possible special sequence for each value of j
    for (int j = 1; j <= m; ++j) {
        dp[1][j] = 1;
    }

    // Fill DP table
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // Calculate the number of special sequences for dp[i][j]
            for (int k = 1; k * 2 <= j; ++k) {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

    // Calculate total number of special sequences
    int totalSpecialSequences = 0;
    for (int j = 1; j <= m; ++j) {
        totalSpecialSequences += dp[n][j];
    }

    return totalSpecialSequences;
}

int main() {
    int m1 = 10, n1 = 4;
    cout << "Number of possible special sequences: " << numberSequence(m1, n1) << endl; // Output: 4

    int m2 = 5, n2 = 2;
    cout << "Number of possible special sequences: " << numberSequence(m2, n2) << endl; // Output: 6

    return 0;
}
