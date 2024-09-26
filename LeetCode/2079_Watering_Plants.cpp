class Solution 
{
public:
    int wateringPlants(vector<int>& plants, int capacity) 
    {
        int cap = capacity;
        int ans = 0;
        int n = plants.size();
        for (int i = 0; i < n; i++)
        {
            if (cap < plants[i])
            {
                ans += (i * 2);
                cap = capacity;
            }
            ans += 1;
            cap -= plants[i];
        }

        return ans;
    }
};
