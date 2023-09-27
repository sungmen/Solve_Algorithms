class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int m = -1;
        int p = -1;
        int g = -1;
        int answer = 0;
        for (int i = garbage.size()-1; i >= 0;i--)
        {
            string cur = garbage[i];
            if (m == -1 && cur.find("M") != string::npos)
            {
                m = i;
            }
            if (p == -1 && cur.find("P") != string::npos)
            {
                p = i;
            }
            if (g == -1 && cur.find("G") != string::npos)
            {
                g = i;
            }
            answer += cur.size();
        }
        int sum = 0;
        for (int i = 0; i < garbage.size() - 1; i++)
        {
            sum += travel[i];
            if (m == i+1) 
                answer += sum;
            if (p == i+1)
                answer += sum;
            if (g == i+1)
                answer += sum;
        }
        return answer;
    }
};