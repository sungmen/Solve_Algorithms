class Solution 
{
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        vector<vector<int>> res;
        priority_queue<pair<int, pair<int,int>>> pq;
        for (int i = 0; i < nums1.size(); i++)
        {
            pq.push({-(nums1[i]+nums2[0]),{i,0}});
        }
        while (!pq.empty() && k--)
        {
            pair<int, pair<int,int>> cur = pq.top();
            int a = cur.second.first;
            int b = cur.second.second;
            pq.pop();
            res.push_back({nums1[a],nums2[b]});
            if (nums2.size()-1 == b) continue;
            pq.push({-(nums1[a]+nums2[b+1]), {a, b+1}});
        }
        return res;
    }
};