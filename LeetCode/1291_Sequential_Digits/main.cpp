class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str = "123456789", lo = to_string(low), hi = to_string(high);
        int losize = lo.size(), hisize = hi.size();
        vector<int> answer;
        for (int i = losize; i <= hisize; i++) {
            for (int j = 0; j <= 9 - i; j++) {
                string tmp = str.substr(j, i);
                string t1 = lo + tmp, t2 = tmp + lo, h1 = hi + tmp, h2 = tmp + hi;
                if ((tmp.size() > losize && tmp.size() < hisize) || (tmp.size() == losize && t1 <= t2) || (tmp.size() == hisize && h1 >= h2)) {
                    if (tmp.size() == losize && losize == hisize && (t1 >= t2 || h1 <= h2)) continue;
                    answer.push_back(stoi(tmp));
                }
            }
        }
        return answer;
    }
};