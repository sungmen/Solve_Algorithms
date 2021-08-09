#include <vector>
#include <map>
using namespace std;
string solution(vector<vector<int>> scores) {
    string answer = "";
    int n = scores.size();
    vector<double> res(n, 0);
    for (int i = 0; i < n; ++i) {
        map<int, vector<int>> m;
        for (int j = 0; j < n; ++j) {
            res[i] += scores[j][i];
            m[scores[j][i]].push_back(j);
        }
        auto it = m.begin(), it2 = m.end();
        it2--;
        if ((it->second.size() == 1 && it->second[0] == i)) {
            res[i] -= it->first;
            res[i] /= n-1;
        } else if (it2->second.size() == 1 && it2->second[0] == i) {
            res[i] -= it2->first;
            res[i] /= n-1;
        } else {
            res[i] /= n;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (res[i] >= 90) answer += 'A';
        else if (res[i] >= 80) answer += 'B';
        else if (res[i] >= 70) answer += 'C';
        else if (res[i] >= 50) answer += 'D';
        else answer += 'F';
    }
    return answer;
}