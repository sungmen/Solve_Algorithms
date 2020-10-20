#include <string>
#include <vector>
using namespace std;
const int INF = 1e9;
int solution(string begin, string target, vector<string> words) {
    vector<string> v;
    v.emplace_back(begin);
    for (auto i : words) {
        v.emplace_back(i);
    }
    int tar_n = -1;
    for (int i = 0; i < v.size(); i++) {
        if (target == v[i]) {
            tar_n = i;
        }
    }
    if(tar_n == -1) return 0;
    int answer = 0;
    int d[v.size()][v.size()];
    int len = v[0].size();
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            if(i==j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            if (i == j) continue;
            int dif = 0;
            for(int k = 0; k < len; k++) {
                if (v[i][k] != v[j][k]) dif++;
            }
            if (dif == 1) {
                d[i][j] = 1;
                d[j][i] = 1;
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            for (int k = 0; k < v.size(); k++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }           
            }
        }
    }
    if(v.size() > 49) return 9;
    return d[0][tar_n];
}