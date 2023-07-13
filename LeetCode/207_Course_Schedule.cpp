class Solution 
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        if (0 == prerequisites.size()) return true;
        queue<int> q;
        vector<vector<int>> v(numCourses);
        vector<int> chk(numCourses);
        for (auto pre : prerequisites)
        {
            v[pre[1]].push_back(pre[0]);
            chk[pre[0]]++;
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (0 == chk[i]) q.push(i);
        }
        int t = 0;
        while (! q.empty())
        {
            int cur = q.front();
            q.pop();
            t++;
            for (auto i : v[cur])
            {
                if (--chk[i] == 0)
                    q.push(i);
            }
        }
        return (t == numCourses ? 1 : 0);
    }
};