class Solution {
public:
    queue<int> q;
    map<int, int, greater<int>> m;
    void inputNum (int i) {
        q.push(i);
        if (m[i]) m[i]++;
        else m[i] = 1;        
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> answer;
        for (int i = 0; i < k; ++i) {
            inputNum(nums[i]);
        }
        answer.push_back(m.begin()->first);
        for (int i = k; i < nums.size(); ++i) {
            if (m[q.front()] == 1) m.erase(q.front());
            else m[q.front()]--;
            q.pop();
            inputNum(nums[i]);
            answer.push_back(m.begin()->first);
        }
        return answer;
    }
};