#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) 
{
    int answer = 0;
    int n = schedules.size();
    
    vector<int> endtime;
    for (int i = 0; i < n; i++)
    {
        int x = schedules[i]%100 + 10;
        int k = 0;
        if (x >= 60)
        {
            k += 1;
            x -= 60;
        }
        int m = ((schedules[i]/100)+k)*60 + (x);
        endtime.push_back(m);
    }
    
    for (int i = 0; i < n; i++)
    {
        int nextTime = startday;
        int js = timelogs[i].size();
        int p = 0;
        for (int j = 0; j < js; j++)
        {
            if (6 == nextTime)
            {
                nextTime++;
                p++;
                continue;
            }
            if (7 == nextTime)
            {
                nextTime = 1;
                p++;
                continue;
            }
            int u = (timelogs[i][j]/100)*60 + (timelogs[i][j]%100);
            if (endtime[i] >= u)
            {
                p++;
            }
            nextTime++;
        }
        if (p == js)
        {
            answer++;
        }
    }
    
    return answer;
}