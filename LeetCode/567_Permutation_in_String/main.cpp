class Solution {
private:
    int arr[26], alp[26], chk[26], cnt = 0;
public:
    bool checkInclusion(string s1, string s2) {
        memset(chk, 1, sizeof(chk));
        for (auto c : s1) {
            if (!arr[c-'a']) {
                cnt++;
                chk[c-'a']=0;
            }
            arr[c-'a']++;
        }
        int n = s1.size();
        for (int i = 0; i < s2.size(); i++) {
            if (i >= n) {
                char c2 = s2[i-n];
                alp[c2-'a']--;
                if (chk[c2-'a']&&alp[c2-'a']!=arr[c2-'a']) {
                    cnt++;
                    chk[c2-'a']=0;
                } else if (!chk[c2-'a']&&alp[c2-'a']==arr[c2-'a']) {
                    cnt--;
                    chk[c2-'a']=1;
                }
            }
            char c = s2[i];
            alp[c-'a']++;
            if (chk[c-'a']&&alp[c-'a']!=arr[c-'a']) {
                cnt++;
                chk[c-'a']=0;
            } else if (!chk[c-'a']&&alp[c-'a']==arr[c-'a']) {
                cnt--;
                chk[c-'a']=1;
            }
            if (cnt == 0) return true;
        }
        return false;
    }
};