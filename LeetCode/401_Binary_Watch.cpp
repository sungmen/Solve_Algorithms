class Solution 
{
public:
    vector<string> readBinaryWatch(int turnedOn) 
    {
        map<int, vector<int>> hour, min;
        for (int i = 0; i <= 11; i++) {
            hour[__builtin_popcount(i)].push_back(i);
        }
        for (int i = 0; i <= 59; i++) {
            min[__builtin_popcount(i)].push_back(i);
        }
        vector<string> ans;
        for (int i = 0; i <= turnedOn; i++) {
            string str = "";
            for (auto h : hour[turnedOn - i]) {
                string ho = to_string(h);
                ho += ":";
                for (auto m : min[i]) {
                    string next = to_string(m);
                    if (next.size() == 1) {
                        next = "0" + next;
                    }
                    ans.push_back(ho + next);
                }
            }
            
        }
        return ans;
    }
};