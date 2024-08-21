class Solution 
{
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) 
    {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end());
        int ans = 0;
        int coreTask = tasks.size() - 1;
        for (int i = 0; i < processorTime.size(); i++)
        {
            ans = max(ans, processorTime[i] + tasks[coreTask]);
            coreTask -= 4;
        }

        return ans;
    }
};
