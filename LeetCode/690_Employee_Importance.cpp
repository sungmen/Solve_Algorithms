/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, vector<int>> um;
    unordered_map<int, int> u;
    int getImportance(vector<Employee*> employees, int id) 
    {
        for (auto it : employees)
        {
            u[it->id] = it->importance;
            um[it->id] = it->subordinates;
        }
        int res = u[id];
        queue<int> q;
        q.push(id);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (auto i : um[cur])
            {
                res += u[i];
                q.push(i);
            }
        }

        return res;
    }
};