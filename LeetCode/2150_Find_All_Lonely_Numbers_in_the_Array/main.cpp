class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        set<int> s, dub;
        for (auto num : nums) {
            if (s.find(num) != s.end()) {
                dub.insert(num);
            }
            if (s.find(num+1) != s.end()) {
                dub.insert(num+1);
                dub.insert(num);
            }
            if (s.find(num-1) != s.end()) {
                dub.insert(num-1);
                dub.insert(num);
            }
            s.insert(num);
        }
        vector<int> answer;
        for (auto it = s.begin(); it != s.end(); it++) {
            if (dub.find(*it) == dub.end()) {
                answer.push_back(*it);
            }
        }
        return answer;    
    }
};
