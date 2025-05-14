class Solution 
{
public:
    int minNumberOperations(vector<int>& target) 
    { 
        int answer = target[0];
        for (int i = 0; i < target.size() - 1; i++)
        {
            if (target[i] < target[i+1])
            {
                answer += target[i+1] - target[i];
            }
        }

        return answer;
    }
};