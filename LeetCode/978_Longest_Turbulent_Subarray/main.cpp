class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        int t = arr[0];
        vector<int> u, d;
        for (int i = 1; i < arr.size(); ++i) {
            if (t < arr[i]) {
                u.push_back(i);
            } else if (t > arr[i]) {
                d.push_back(i);
            }
            t = arr[i];
        }
        int l = 0, r = 0;
        int res = 1, cnt = 1, c = 0, tmp = 2;
        while (cnt < arr.size()) {
            if (l < u.size() && cnt == u[l]) {
                if (c == 2) {
                    tmp++;
                    c = 1;
                } else {
                    tmp = 2;
                    c = 1;
                }
                l++;
            } else if (r < d.size() && cnt == d[r]) {
                if (c == 1) {
                    tmp++;
                    c = 2;
                } else {
                    tmp = 2;
                    c = 2;
                }
                r++;
            } else {
                tmp = 1;
                c = 0;
            }
            cnt++;
            res = max(res, tmp);
        }
        return res;
    }
};