#include <bits/stdc++.h>
using namespace std;
string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    map<int, string> result;
    map<string, int> languagesMap;
    for (int i = 0; i < languages.size(); ++i) {
        languagesMap[languages[i]] = preference[i];
    }
    vector<map<string, int>> tableMap(table.size());
    for (int i = 0; i < table.size(); ++i) {
        int cnt = 6, j = 0, sum = 0;
        string str = "";
        string name = "";
        while (j < table[i].size()) {
            if (table[i][j] != ' ') {
                str += table[i][j];
            } else {
                if (cnt == 6) {
                    name = str;
                } else {
                    if (languagesMap[str]) {
                        sum += languagesMap[str] * cnt;
                    }
                }
                str = "";
                --cnt;
            }
            j++;
        }
        if (languagesMap[str]) {
            sum += languagesMap[str] * cnt;
        }
        if (result.find(sum) == result.end()) {
            result[sum] = name;            
        } else {
            result[sum] = (result[sum][0] > name[0] ? name : result[sum]);
        }
    }
    auto itresult = result.end();
    itresult--;
    return itresult->second;
}