class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        map<char, int> m;
        m[keysPressed[0]] = releaseTimes[0];
        for (int i = 1; i < releaseTimes.size(); ++i) {
            if (m.find(keysPressed[i]) == m.end())
                m[keysPressed[i]] = releaseTimes[i] - releaseTimes[i-1];
            else if (m.find(keysPressed[i])->second < releaseTimes[i] - releaseTimes[i-1]) 
                m[keysPressed[i]] = releaseTimes[i] - releaseTimes[i-1];
            
        }
        char res;
        long long r = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second >= r) {
                res = it->first;
                r = it->second;
            }            
        }
        return res;
    }
};