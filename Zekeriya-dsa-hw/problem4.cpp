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

// Function to find the length of the longest chain of pairs
int maxChainLen(vector<Pair>& pairs) {
    // Sort the pairs based on their second number (end of the pair)
    sort(pairs.begin(), pairs.end(), comparePairs);

    int maxLength = 1; // Initialize the maximum length of the chain
    int currentEnd = pairs[0].second; // Initialize the end of the current chain

    // Iterate through the sorted pairs
    for (int i = 1; i < pairs.size(); i++) {
        // If the start of the current pair is greater than or equal to the end of the previous pair,
        // include it in the chain and update the end of the current chain
        if (pairs[i].first > currentEnd) {
            maxLength++;
            currentEnd = pairs[i].second;
        }
    }

    return maxLength;
}

int main() {
    // Example usage
    vector<Pair> pairs = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    cout << "Length of the longest chain: " << maxChainLen(pairs) << endl;
    return 0;
}
