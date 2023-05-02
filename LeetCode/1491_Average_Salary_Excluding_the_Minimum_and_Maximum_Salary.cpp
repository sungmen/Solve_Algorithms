class Solution 
{
public:
    double average(vector<int>& salary) 
    {
        sort(salary.begin(), salary.end())    ;
        int res = 0;
        for (int i = 1; i < salary.size() - 1; i++)
        {
            res += salary[i];
        }    
        return (double)res / (salary.size() - 2);
    }
};