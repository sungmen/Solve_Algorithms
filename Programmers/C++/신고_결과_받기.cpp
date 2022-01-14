#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
using namespace std;
vector<string> split(string str) {
    vector<string> res;
    istringstream ss(str);
    string token;
    while (getline(ss, token, ' ')) {
        res.push_back(token);
    }
    return res;
}
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, set<string>> li;
    map<string, int> ms;
    for (auto tmp : report) {
        vector<string> vs = split(tmp);
        if (li[vs[0]].find(vs[1]) == li[vs[0]].end()) {
            li[vs[0]].insert(vs[1]);
            ms[vs[1]]++;
        }
    }
    for (auto id : id_list) {
        int res = 0;
        for (auto it = li[id].begin(); it != li[id].end(); ++it) {
            if (ms[*it] >= k) {
                res++;
            }
        }
        answer.push_back(res);
    }
    return answer;
}