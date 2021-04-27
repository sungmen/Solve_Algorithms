class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        for (int i = 0; i < heights.size() - 1; i++) {
            if (heights[i] < heights[i+1]) {
                pq.push(-(heights[i+1]-heights[i]));
                if (pq.size() > ladders) {
                    bricks += pq.top();
                    pq.pop();
                }
                if (bricks < 0) {
                    return i;
                }
            }
        }
        return heights.size()-1;
    }
};