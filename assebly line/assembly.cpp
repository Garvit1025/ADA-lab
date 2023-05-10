#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task
{
    int start_time;
    int end_time;
    int task_id;
};

bool compare(Task a, Task b)
{
    if (a.start_time != b.start_time)
        return a.start_time < b.start_time;
    return a.end_time < b.end_time;
}

void assemblyLineScheduling(vector<Task> tasks)
{
    sort(tasks.begin(), tasks.end(), compare);

    int n = tasks.size();
    int line1_end = 0, line2_end = 0;
    int i = 0, j = 0;
    vector<int> line1_tasks, line2_tasks;

    while (i < n && j < n)
    {
        if (tasks[i].start_time <= line1_end && tasks[i].start_time <= line2_end)
        {
            if (line1_end <= line2_end)
            {
                line1_end = tasks[i].end_time;
                line1_tasks.push_back(tasks[i++].task_id);
            }
            else
            {
                line2_end = tasks[i].end_time;
                line2_tasks.push_back(tasks[i++].task_id);
            }
        }
        else if (tasks[i].start_time <= line1_end && tasks[i].start_time > line2_end)
        {
            line2_end = tasks[i].end_time;
            line2_tasks.push_back(tasks[i++].task_id);
        }
        else if (tasks[i].start_time > line1_end && tasks[i].start_time <= line2_end)
        {
            line1_end = tasks[i].end_time;
            line1_tasks.push_back(tasks[i++].task_id);
        }
        else
        {
            if (line1_end <= line2_end)
            {
                line1_end = tasks[i].end_time;
                line1_tasks.push_back(tasks[i++].task_id);
            }
            else
            {
                line2_end = tasks[i].end_time;
                line2_tasks.push_back(tasks[i++].task_id);
            }
        }
    }

    cout << "Tasks performed on line 1: ";

    if (line1_tasks.empty())
    {
        cout << "No tasks performed on line 1";
    }
    else
    {
        for (int i = 0; i < line1_tasks.size(); i++)
        {
            cout << line1_tasks[i] << " ";
        }
    }

    cout << "\nTasks performed on line 2: ";
    if (line2_tasks.empty())
    {
        cout << "No tasks performed on line 2";
    }
    else
    {
        for (int i = 0; i < line2_tasks.size(); i++)
        {
            cout << line2_tasks[i] << " ";
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of tasks: ";
    cin >> n;

    vector<Task> tasks;
    for (int i = 0; i < n; i++)
    {
        Task t;
        cout << "Enter start time, end time and task id of task " << i + 1 << ": ";
        cin >> t.start_time >> t.end_time >> t.task_id;
        tasks.push_back(t);
    }

    assemblyLineScheduling(tasks);
    return 0;
}
