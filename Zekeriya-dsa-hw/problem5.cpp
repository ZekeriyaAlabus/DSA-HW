#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a pair of numbers
struct Pair {
    int first; // First number of the pair
    int second; // Second number of the pair
};

// Function to compare pairs based on their second number (end of the pair)
bool comparePairs(Pair p1, Pair p2) {
    return p1.second < p2.second;
}

// Function to find the length of the longest chain of pairs using dynamic programming
int maxChainLen(vector<Pair>& pairs) {
    // Sort the pairs based on their second number (end of the pair)
    sort(pairs.begin(), pairs.end(), comparePairs);

    int n = pairs.size();
    vector<int> dp(n, 1); // Initialize dp array with all elements as 1

    // Iterate through the sorted pairs
    for (int i = 1; i < n; i++) {
        // Iterate from index 0 to i-1 to find the longest chain ending at pairs[i]
        for (int j = 0; j < i; j++) {
            // If pairs[j].second < pairs[i].first and dp[i] < dp[j] + 1,
            // update dp[i] to dp[j] + 1
            if (pairs[j].second < pairs[i].first && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    // Find the maximum value in dp array
    int maxLength = *max_element(dp.begin(), dp.end());

    return maxLength;
}

int main() {
    // Example usage
    vector<Pair> pairs = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    cout << "Length of the longest chain: " << maxChainLen(pairs) << endl;
    return 0;
}
