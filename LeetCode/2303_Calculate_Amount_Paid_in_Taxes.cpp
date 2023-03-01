class Solution 
{
public:
    double calculateTax(vector<vector<int>>& brackets, int income) 
    {
        double res = 0.0;
        int back = 0;
        for (auto bracket : brackets)
        {
            int cur = bracket[0] - back;
            if (cur >= income)
            {
                res += (income * (bracket[1]/100.0));
                return res;
            }
            else
            {
                res += (cur * (bracket[1]/100.0));
                income -= cur;
                back = bracket[0];
            }
        }
        return res;
    }
};