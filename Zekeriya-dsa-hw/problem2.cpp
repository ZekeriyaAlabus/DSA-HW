#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a job
struct Job {
    int id; // Job ID
    int deadline; // Deadline of the job
    int profit; // Profit associated with the job
};

// Function to compare jobs based on their profits (in decreasing order)
bool compareJobs(Job j1, Job j2) {
    return (j1.profit > j2.profit);
}

// Function to find the number of jobs done and the maximum profit
pair<int, int> maxJobsAndProfit(vector<Job>& jobs) {
    // Sort the jobs based on their profits
    sort(jobs.begin(), jobs.end(), compareJobs);

    // Find the maximum deadline
    int maxDeadline = 0;
    for (const auto& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // Initialize an array to keep track of time slots
    vector<int> timeSlots(maxDeadline, 0);

    int totalProfit = 0;
    int numJobsDone = 0;

    // Iterate through the sorted jobs
    for (const auto& job : jobs) {
        // Find the maximum available time slot before the deadline
        for (int i = job.deadline - 1; i >= 0; i--) {
            if (timeSlots[i] == 0) {
                // If a time slot is available, schedule the job
                timeSlots[i] = job.id;
                totalProfit += job.profit;
                numJobsDone++;
                break;
            }
        }
    }

    return make_pair(numJobsDone, totalProfit);
}

int main() {
    vector<Job> jobs = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    auto result = maxJobsAndProfit(jobs);
    cout << "Number of jobs done: " << result.first << endl;
    cout << "Maximum profit: " << result.second << endl;
    return 0;
}
