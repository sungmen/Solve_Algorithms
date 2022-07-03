class Solution {
public:
    string sortString(string s) {
        vector<int> arr(26, 0);
        for (char chr : s) {
            arr[chr-'a']++;
        }
        string res = "";
        while(1) {
            bool chk = false;
            for (int i = 0; i < 26; i++) {
                if (arr[i]) {
                    res += (i + 'a');
                    arr[i]--;
                    chk = true;
                }
            }
            if (!chk) break;
            chk = false;
            for (int i = 25; i >= 0; i--) {
                if (arr[i]) {
                    res += (i + 'a');
                    arr[i]--;
                    chk = true;
                }
            }            
            if (!chk) break;
        }
        return res;
    }
};