class FindSumPairs 
{
public:
    map<int, int> m1, m2;
    vector<int> nums1, nums2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
    {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (auto n : nums1)
            m1[n] ++;
        for (auto n : nums2)
            m2[n] ++;
    }
    
    void add(int index, int val) 
    {
        int p = nums2[index];
        m2[p]--;
        if (m2[p] == 0)
            m2.erase(p);
        nums2[index] += val;
        m2[nums2[index]]++;
    }
    
    int count(int tot) 
    {
        int res = 0;
        for (auto it = m1.begin(); it != m1.end(); it++)
        {
            int t = tot - it->first;
            if (t < 0) continue;
            if (m2.find(t) == m2.end()) continue;
            res += (it->second * m2[t]);
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */