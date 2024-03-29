class SeatManager 
{
public:
    priority_queue<int> pq;
    
    SeatManager(int n) 
    {
        for (int i = 1; i <= n; i++)    
        {
            pq.push(-i);
        }
    }
    
    int reserve() 
    {
        int p = -pq.top();
        pq.pop();
        return p;
    }
    
    void unreserve(int seatNumber) 
    {
        pq.push(-seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */