class Solution 
{
public:
    int minGroups(vector<vector<int>>& intervals) 
    {
        int res = 1;
        sort(intervals.begin(), intervals.end());
        priority_queue<int> pq;
        pq.push(-intervals[0][1]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (pq.top() <= -intervals[i][0]) res++;
            else pq.pop();
            pq.push(-intervals[i][1]);
        }
        return res;
    }
};