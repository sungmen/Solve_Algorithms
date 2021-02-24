#include <bits/stdc++.h>
using namespace std;
int solution(string s)
{
    int SIZE = s.size();
    if(!SIZE || SIZE == 1) return s.size();
    int d[SIZE][SIZE];
    int l, r, MAX = 0;
    memset(d, 0, sizeof(d));
    for (int i = SIZE-1; i >= 0; --i) {
        for (int j = i; j < SIZE; j++) {
            if (i == j) d[i][j] = 1;
            else if (s[i] == s[j]) {
                if (j - i == 1) d[i][j] = 1;
                else d[i][j] = d[i+1][j-1];
            }
            if (d[i][j] && j - i >= MAX) {
                MAX = j - i;
                l = i;
                r = j;
            }
        }
    }
    return r-l+1;
}