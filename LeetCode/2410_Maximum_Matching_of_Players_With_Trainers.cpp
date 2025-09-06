class Solution 
{
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) 
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int p_ = players.size();
        int t_ = trainers.size();

        int p_s = p_ - 1;
        int t_s = t_ - 1;

        int answer = 0;

        while (p_s >= 0 && t_s >= 0)
        {
            int p_v = players[p_s];
            int t_v = trainers[t_s];
            if(p_v <= t_v)
            {
                t_s--;
                answer++;
            }
            p_s--;
        }
        return answer;
    }
};
