class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 1) return true;
        int k = (word[0] < 91 ? 1 : 2);
        int r = (word[1] < 91 ? 1 : 2);
        if (k > r) return false;
        for (int i = 2; i < word.size(); i++)
        {
            int c = (word[i] < 91 ? 1 : 2);
            if (r != c)
                return false;
        }
        return true;
    }
};