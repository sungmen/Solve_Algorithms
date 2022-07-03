class KthLargest {
public:
    priority_queue<int> pq;
    int k_;
    
    void pq_chk()
    {
        if (pq.size() > k_)
        {
            pq.pop();
        }
    }
    
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for (auto num : nums)
        {
            pq.push(-num);
            pq_chk();
        }
    }
    
    int add(int val) {
        pq.push(-val);
        pq_chk();
        
        return -pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */