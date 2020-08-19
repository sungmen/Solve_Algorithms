#include<bits/stdc++.h>
using namespace std;
int pos[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
set<string> s;
void dfs(string str, vector<vector<int>> v, int x, int y, int idx) {
    str += char(v[x][y]+48);
    if(str.size()==7){
        s.insert(str);
        return;
    }
    for(int i = 0; i < 4; i++) {
        int x_ = x + pos[i][0];
        int y_ = y + pos[i][1];
        if (x_ >= 0 && x_ < 4 && y_ >= 0 && y_ < 4) {
            dfs(str, v, x_, y_, ++idx);
        }
    }
}
int main() {
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++) {
        s.clear();
        vector<vector<int> > v(4, vector<int>(4));
        for(int i = 0; i < 4; i++) {
            for (int j = 0 ; j < 4; j++) {
                cin >> v[i][j];
            }
        }
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                string str = "";
                cout<<i << ' ' << j << '\n';
                dfs(str, v, i, j, 0);
            }
        }
        cout << '#' << test << ' ' << s.size() << '\n';
    }
}