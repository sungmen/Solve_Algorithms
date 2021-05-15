class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n));
        pair<int, int> t = {n-1, 3};
        int d = 0;
        pair<int, int> p = {0, 0};
        int cnt = 1;
        v[0][0] = cnt++;
        while(t.first > 0) {
            if (0 == d) {
                for (int i = 0; i < t.first; i++) {
                    v[p.first][++p.second] = cnt++;
                }
            } else if (1 == d) {
                for (int i = 0; i < t.first; i++) {
                    v[++p.first][p.second] = cnt++;
                }                
            } else if (2 == d) {
                for (int i = 0; i < t.first; i++) {
                    v[p.first][--p.second] = cnt++;
                }                
            } else if (d == 3)  {
                for (int i = 0; i < t.first; i++) {
                    v[--p.first][p.second] = cnt++;
                } 
            }
            d++;
            if (d == 4) d = 0;
            t.second--;
            if (t.second == 0) {
                t.first--;
                t.second = 2;
            }
        }
        return v;
    }
};