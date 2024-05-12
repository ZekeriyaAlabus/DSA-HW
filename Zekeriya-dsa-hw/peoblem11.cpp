#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // Include numeric header for accumulate function

using namespace std;

bool isValid(vector<int>& pages, int students, int maxPages) {
    int currentPages = 0;
    int currentStudents = 1;

    for (int page : pages) {
        if (page > maxPages) {
            return false; // Not possible to allocate
        }
        if (currentPages + page > maxPages) {
            currentStudents++;
            currentPages = page;
            if (currentStudents > students) {
                return false; // Too many students required
            }
        } else {
            currentPages += page;
        }
    }

    return true;
}

int findPages(vector<int>& A, int N, int M) {
    if (N < M) {
        return -1; // Not enough books for each student
    }

    int low = *max_element(A.begin(), A.end()); // Minimum value
    int high = accumulate(A.begin(), A.end(), 0); // Maximum value
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isValid(A, M, mid)) {
            result = mid;
            high = mid - 1; // Try to minimize maximum pages allocated
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    vector<int> A1 = {12, 34, 67, 90};
    int N1 = 4, M1 = 2;
    cout << "Minimum Maximum Pages: " << findPages(A1, N1, M1) << endl; // Output: 113

    vector<int> A2 = {15, 17, 20};
    int N2 = 3, M2 = 2;
    cout << "Minimum Maximum Pages: " << findPages(A2, N2, M2) << endl; // Output: 32

    return 0;
}
