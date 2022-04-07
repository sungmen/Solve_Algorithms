class MedianFinder 
{
private:
    priority_queue<int> pq; // 4 3 2 1
    priority_queue<int, vector<int>, greater<int>> pq2; // 8 9 10 11
        
public:
    MedianFinder() {}
    
    void addNum(int num) 
    {
        if (pq.empty() || pq2.empty())
        {
            pq2.push(num);
            if (pq2.size() == 2) 
            {
                pq.push(pq2.top());
                pq2.pop();
            }
        }
        else if (pq.top() >= num)
        {
            pq.push(num);
            if (pq.size() > pq2.size())
            {
                pq2.push(pq.top());
                pq.pop();
            }
        }
        else if (pq2.top() <= num)
        {
            pq2.push(num);
            if (pq2.size() > pq.size() + 1)
            {
                pq.push(pq2.top());
                pq2.pop();
            }
        }
        else if (pq.size() == pq2.size())
        {
            pq2.push(num);
        }
        else
        {
            pq.push(num);
        }
    }
    
    double findMedian() 
    {
        if (pq.size() == pq2.size())
        {
            return (pq.top() + pq2.top()) / 2.0;       
        }
        return (double)pq2.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */