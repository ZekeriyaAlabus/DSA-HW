#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int kthElementUtil(vector<int>& arr1, vector<int>& arr2, int start1, int end1, int start2, int end2, int k) {
    // If arr1 is empty, return kth element of arr2
    if (start1 > end1) {
        return arr2[start2 + k - 1];
    }
    // If arr2 is empty, return kth element of arr1
    if (start2 > end2) {
        return arr1[start1 + k - 1];
    }
    // Base case: if k is 1, return minimum of first elements of arr1 and arr2
    if (k == 1) {
        return min(arr1[start1], arr2[start2]);
    }

    int mid1 = (start1 + end1) / 2;
    int mid2 = (start2 + end2) / 2;

    // If k is greater than the number of elements in arr1 and arr2 combined
    if (k > (mid1 - start1 + 1) + (mid2 - start2 + 1)) {
        // If mid element of arr1 is less than mid element of arr2
        if (arr1[mid1] < arr2[mid2]) {
            // Exclude elements of arr1 before mid1 and adjust k accordingly
            return kthElementUtil(arr1, arr2, mid1 + 1, end1, start2, end2, k - (mid1 - start1 + 1));
        } else {
            // Exclude elements of arr2 before mid2 and adjust k accordingly
            return kthElementUtil(arr1, arr2, start1, end1, mid2 + 1, end2, k - (mid2 - start2 + 1));
        }
    } else {
        // If mid element of arr1 is less than mid element of arr2
        if (arr1[mid1] < arr2[mid2]) {
            // Exclude elements of arr2 after mid2 and adjust k accordingly
            return kthElementUtil(arr1, arr2, start1, end1, start2, mid2, k);
        } else {
            // Exclude elements of arr1 after mid1 and adjust k accordingly
            return kthElementUtil(arr1, arr2, start1, mid1, start2, end2, k);
        }
    }
}

int kthElement(vector<int>& arr1, vector<int>& arr2, int N, int M, int k) {
    return kthElementUtil(arr1, arr2, 0, N - 1, 0, M - 1, k);
}

int main() {
    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};
    int N = arr1.size();
    int M = arr2.size();
    int k1 = 5;

    cout << "Kth Element: " << kthElement(arr1, arr2, N, M, k1) << endl; // Output: 6

    vector<int> arr3 = {100, 112, 256, 349, 770};
    vector<int> arr4 = {72, 86, 113, 119, 265, 445, 892};
    int N2 = arr3.size();
    int M2 = arr4.size();
    int k2 = 7;

    cout << "Kth Element: " << kthElement(arr3, arr4, N2, M2, k2) << endl; // Output: 256

    return 0;
}
