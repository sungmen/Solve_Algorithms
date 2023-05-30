class Solution 
{
public:
    string tictactoe(vector<vector<int>>& moves) 
    {
        if (moves.size() < 5) return "Pending";
        int i = moves.size() - 1;
        unordered_map<int, unordered_map<int, int>> um;
        string ans = moves.size()%2?"A":"B";
        while (i >= 0)
        {
            um[moves[i][0]][moves[i][1]] = 1;
            i -= 2;
        }
        for (auto it = um.begin(); it != um.end(); it++)
        {
            if (it->second.size() == 3) return ans;
        }
        for (int i = 0; i < 3; i++)
        {
            if (um[0][i] && um[1][i] && um[2][i]) return ans;
        }
        if ((um[0][0] && um[1][1] && um[2][2]) || (um[0][2] && um[1][1] && um[2][0])) return ans;


        return (moves.size() == 9 ? "Draw" : "Pending");
    }
};