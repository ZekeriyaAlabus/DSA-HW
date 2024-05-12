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

// Function to compare jobs based on their deadlines (in non-decreasing order)
bool compareJobs(Job j1, Job j2) {
    return (j1.deadline < j2.deadline);
}

// Function to find the maximum profit using dynamic programming
pair<int, int> maxJobsAndProfit(vector<Job>& jobs) {
    // Sort the jobs based on their deadlines
    sort(jobs.begin(), jobs.end(), compareJobs);

    // Find the maximum deadline
    int maxDeadline = 0;
    for (const auto& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // Initialize a 1D array to store the maximum profit at each time slot
    vector<int> dp(maxDeadline + 1, 0);

    // Iterate through the sorted jobs
    for (const auto& job : jobs) {
        // Find the maximum available time slot before the deadline starting from the deadline down to 1
        for (int i = job.deadline; i >= 1; i--) {
            if (dp[i] == 0) {
                // If the time slot is available, update dp with the maximum profit considering this job
                dp[i] = job.profit;
                break;
            }
        }
    }

    int totalProfit = 0;
    int numJobsDone = 0;

    // Calculate the total profit and the number of jobs done
    for (int i = 1; i <= maxDeadline; i++) {
        totalProfit += dp[i];
        if (dp[i] != 0) {
            numJobsDone++;
        }
    }

    return make_pair(numJobsDone, totalProfit);
}

int main() {
    vector<Job> jobs = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 
