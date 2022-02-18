#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
vector<string> strsplit(string str) {
    stringstream inputs(str);
    string tmp = "";
    vector<string> ret;
    while(getline(inputs, tmp, ' ')) {
        ret.push_back(tmp);
    }
    return ret;
}
int caltime(string str) {
    int res = 0;
    for (int i = 0; i <= 1; i++) {
        res *= 10;
        res += (str[i]-'0');
    }
    res *= 60;
    int tmp = 0;
    for (int i = 3; i <= 4; i++) {
        tmp *= 10;
        tmp += (str[i]-'0');
    }
    return res + tmp;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> in, res;
    for (auto record : records) {
        vector<string> vs = strsplit(record);
        if (vs[2] == "OUT") {
            res[vs[1]] += (caltime(vs[0])-in[vs[1]]);
            in.erase(vs[1]);
        } else {
            in[vs[1]] = caltime(vs[0]);
        }
    }
    int ltime = caltime("23:59");
    for (auto it = in.begin(); it != in.end(); it++) {
        res[it->first] += (ltime - it->second);
    }
    for (auto it = res.begin(); it != res.end(); it++) {
        int r = it->second - fees[0];
        int value = fees[1];
        if (r > 0) {
            r = ceil((double)r / fees[2]);
            value += fees[3] * r;
        }
        answer.push_back(value);
    }
    return answer;
}