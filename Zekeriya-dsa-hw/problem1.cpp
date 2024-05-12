#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a meeting
struct Meeting {
    int start; // Start time of the meeting
    int end; // End time of the meeting
    int pos; // Position of the meeting in the original array
};

// Function to compare meetings based on their end time
bool compareMeetings(Meeting m1, Meeting m2) {
    // Sort meetings based on their end times
    return (m1.end < m2.end);
}

// Function to find the maximum number of meetings that can be accommodated
int maxMeetings(int start[], int end[], int n) {
    vector<Meeting> meetings(n);
    for (int i = 0; i < n; i++) {
        // Populate the meeting structure with start, end, and position
        meetings[i].start = start[i];
        meetings[i].end = end[i];
        meetings[i].pos = i + 1;
    }

    // Sort the meetings based on their end time
    sort(meetings.begin(), meetings.end(), compareMeetings);

    // Initial meeting is always selected
    int count = 1;

    // Initialize end time of the first meeting
    int currentEnd = meetings[0].end;

    // Check for all meetings whether they are compatible with the previously selected meeting or not
    for (int i = 1; i < n; i++) {
        if (meetings[i].start > currentEnd) {
            // If the current meeting's start time is after the end time of the previously selected meeting, then select this meeting
            count++;
            currentEnd = meetings[i].end;
        }
    }
    return count;
}

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);

    // Output the maximum number of meetings
    cout << "Maximum number of meetings: " << maxMeetings(start, end, n) << endl;

    return 0;
}
