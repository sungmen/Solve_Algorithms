class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long r = 0;
        for (auto s : shifts) r += s;
        for (int i = 0; i < s.size(); ++i) {
            int t = ((s[i] - 'a') + r) % 26;
            s[i] = t + 'a';
            r -= shifts[i];
        }
        return s;
    }
};