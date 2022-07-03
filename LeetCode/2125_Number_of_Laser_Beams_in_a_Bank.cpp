class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> v;
        for (auto str : bank) {
            int tmp = 0;
            for (auto c : str) {
                if (c == '1') tmp++;
            }
            if (tmp) v.push_back(tmp);
        }
        int answer = 0;
        for(int i = 1; i < v.size(); i++) {
            answer += (v[i] * v[i-1]);
        }
        return answer;
    }
};