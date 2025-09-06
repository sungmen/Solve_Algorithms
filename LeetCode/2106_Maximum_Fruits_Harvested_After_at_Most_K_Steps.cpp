class Solution 
{
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) 
    {
        vector<vector<int>> vecL, vecR;
        int answer = 0;
        int nVecL = 0, nVecR = 0;
        int index = 0;
        vecR.push_back({0, 0});
        int mid = 0;
        for (int i = 0; i < fruits.size(); i++)
        {
            if (fruits[i][0] == startPos)
            {
                mid = fruits[i][1];
            }
            else if (fruits[i][0] < startPos)
            {
                index = i;
            }
            else
            {
                nVecR += fruits[i][1];
                vecR.push_back({fruits[i][0]-startPos, nVecR});
            }
        }
        vecL.push_back({0, 0});
        for (int i = index; i >= 0; i--)
        {
            if (fruits[i][0] >= startPos)
            {
                continue;
            }
            nVecL += fruits[i][1];
            vecL.push_back({startPos-fruits[i][0], nVecL});
        }

        int left = vecL.size()-1, right = 0;
        while (left > -1 && right < vecR.size())
        {
            while (right < vecR.size() && k >= min((vecL[left][0]*2)+vecR[right][0], vecL[left][0]+(vecR[right][0]*2)))
            {
                answer = max(answer, mid + vecL[left][1] + vecR[right][1]);
                right++;
            }
            left--;
        }
        
        return answer;
    }
};