class Solution {
public:
    string movelr(int wt) {
        if (wt > 0) {
            string tmpp(wt,'L');
            return tmpp;
        } else if (wt < 0) {
            string tmpp(-wt,'R');
            return tmpp;
        }
        return "";
    }
    string alphabetBoardPath(string target) {
        pair<int,int> cur = {0, 0};
        string str = "";
        for (auto t : target) {
            int h = (t - 'a') / 5, w = (t - 'a') % 5;
            int ht = cur.first - h, wt = cur.second - w;
            if (ht > 0) {
                string tmp(ht,'U');
                str += tmp;
                str += movelr(wt);
            } else if (ht < 0) {
                str += movelr(wt);
                string tmp(-ht,'D');
                str += tmp;                
            } else {
                str += movelr(wt);
            }
            str += '!';
            cur = {h, w};
        }
        return str;
    }
};