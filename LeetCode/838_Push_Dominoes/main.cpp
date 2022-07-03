class Solution {
public:
    string pushDominoes(string d) {
        int i = 0, l = 0, r = 0, start = -1, end = d.size()-1;
        
        while (i < d.size()) {
            if (d[i] == 'L') {
                l = i;
                while (l >= 0) {
                    d[l] = 'L';
                    l--;
                }
                start = i;
                l = i;
            }
            if (d[i] == 'R') break;
            i++;
        }
        i = d.size() - 1;
        while (i >= 0) {
            if (d[i] == 'R') {
                r = i;
                while (r < d.size()) {
                    d[r++] = 'R';
                }
                end = i;
            }
            if (d[i] == 'L') break;
            i--;
        }
        r = -1;
        start ++;
        while (start <= end) {
            if (d[start] == 'R') {
                if ( r >= l) {
                    int t = r;
                    while (t <= start) {
                        d[t++] = 'R';
                    }   
                }
                r = start;
            } else if (d[start] == 'L') {
                if (l > r) {
                    int t = start;
                    while (t >= l) {
                        d[t--] = 'L';
                    }
                } else {
                    int t1 = r, t2 = start;
                    while (t1 < t2) {
                        d[t1++] = 'R';
                        d[t2--] = 'L';
                    }
                }
                l = start;
            }            
            start++;
        }
        return d;
    }
};