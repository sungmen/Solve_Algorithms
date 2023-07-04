class Solution 
{
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int f = 0, t = 0;
        for (auto it : bills)
        {
            switch (it)
            {
            case 5:
            {
                f++;
                break;
            }
            case 10:
            {
                if (f == 0)
                    return false;
                f--;
                t++;
                break;
            }
            default:
            {
                if (f > 0 && t > 0)
                {
                    f--;
                    t--;
                    break;
                }
                else if (f >= 3)
                {
                    f -= 3;
                    break;
                }
                return false;
            }
            }
        }
        return true;
    }
};