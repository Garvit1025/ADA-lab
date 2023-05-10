#include <iostream>
#include <vector>
#include <algorithm>

// Define a custom struct to hold activity information
struct Activity
{
    int start, end;
};

// Comparator function for sorting activities by end times
bool compare_activities(Activity a, Activity b)
{
    return a.end < b.end;
}

// Function to find the maximum number of non-conflicting activities
int max_activities(std::vector<Activity> activities)
{
    // Sort activities by end times
    std::sort(activities.begin(), activities.end(), compare_activities);

    int count = 1; // The first activity is always selected
    int last_activity_end = activities[0].end;

    // Iterate through the remaining activities
    for (size_t i = 1; i < activities.size(); ++i)
    {
        // Check if the current activity's start time is not conflicting with the last selected activity's end time
        if (activities[i].start >= last_activity_end)
        {
            count++;                               // Increment the count of non-conflicting activities
            last_activity_end = activities[i].end; // Update the last selected activity's end time
        }
    }

    return count;
}

int main()
{
    std::vector<Activity> activities = {
        {1, 4},
        {3, 5},
        {0, 6},
        {5, 7},
        {3, 9},
        {5, 9},
        {6, 10},
        {8, 11},
        {8, 12},
        {2, 14},
        {12, 16}};

    int result = max_activities(activities);
    std::cout << "The maximum number of non-conflicting activities is: " << result << std::endl;

    return 0;
}