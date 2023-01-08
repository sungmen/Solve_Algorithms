class Solution 
{
private:
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        sort(points.begin(), points.end());
        int res = 1;
        for (int i = 0; i < points.size(); i++)
        {
            if (res >= points.size() - i)
                break;
            int y = points[i][0], x = points[i][1];
            map<double, int> ymap, xmap, m;
            for (int j = 0; j < points.size(); j++)
            {
                if (i == j) continue;
                int y_ = points[j][0], x_ = points[j][1];
                if (0 == (x_-x))
                    ymap[x]++;
                else if (0 == (y_-y))
                    xmap[y]++;
                else
                    m[(double(y_-y)/double(x_-x))]++;
            }
            for (auto it = m.begin(); it != m.end(); it++)
            {
                if (res < it->second + 1)
                    res = it->second + 1;
            }
            for (auto it = ymap.begin(); it != ymap.end(); it++)
            {
                if (res < it->second + 1)
                    res = it->second + 1;
            }
            for (auto it = xmap.begin(); it != xmap.end(); it++)
            {
                if (res < it->second + 1)
                    res = it->second + 1;
            }
        }

        return res;
    }
};