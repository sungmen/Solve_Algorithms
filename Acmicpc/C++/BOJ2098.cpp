// TSP Algorithm
// Travelling salesman problem

#include <bits/stdc++.h> 
using namespace std; 
int v[16][16], b[16][1<<16], n;
#define INF 987654321
int tsp(int c, int visit) { 
    int& ret = b[c][visit];
    if(ret != -1) return ret;
    if(visit == (1 << n) - 1) {
        if (v[c][0] != 0) return v[c][0];
        else return INF;
    }
    ret = INF;
    for (int i = 0; i < n; i++) {
        if (v[c][i] && !(visit & (1 << i))) {
            int vis = visit | (1 << i);
            ret = min(ret, tsp(i, vis) + v[c][i]);
        }
    }
    return ret;
}
int main() { 
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    memset(b, -1, sizeof(b));
	cout << tsp(0,1); 
	return 0; 
} 