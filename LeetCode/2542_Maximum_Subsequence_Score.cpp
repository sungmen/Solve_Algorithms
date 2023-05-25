class Solution
{
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int n = nums1.size();
        long long ans = 0, s = 0;
        vector<pair<int, int>> v;
        priority_queue<int> pq;
        for (int i = 0; i < n;i ++)
        {
            v.push_back({-nums2[i], -nums1[i]});
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            int num2 = -v[i].first;
            int num1 = -v[i].second;
            s += num1;
            pq.push(-num1);
            if (k - 1 > i) continue;
            ans = max(ans, s * num2);
            int cur = pq.top();
            pq.pop();
            s += cur;
        }
        return ans;
    }
};