class Solution 
{
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        vector<int> res;

        for (auto it : asteroids)
        {
            if (it >= 0)
            {
                res.push_back(it);
                continue;
            }
            bool b = 1;
            while (!res.empty())
            {
                if (res.back() < 0)
                {
                    b = 1;
                    break;
                }
                else if (-it > res.back())
                {
                    b = 1;
                    res.pop_back();
                }
                else if (-it == res.back())
                {
                    b = 0;
                    res.pop_back();
                    break;
                }
                else
                {
                    b = 0;
                    break;
                }
            }
            if (!b) continue;
            res.push_back(it);
        }

        return res;
    }
};