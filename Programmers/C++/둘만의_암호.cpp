#include <map>
using namespace std;
string solution(string s, string skip, int index) 
{
    string answer = "";
    map<char, int> m, nm;
    map<int, char> n;
    for (int i = 0; i < 26; i++)
        m['a'+i]=1;
    for (auto cur : skip)
        m.erase(cur);
    int c = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        n[c] = it->first;
        nm[it->first] = c++;
    }
    int cnt = m.size();
    for (auto str : s)
    {
        int cur = nm[str] + index;
        while (cur >= cnt)
            cur-=cnt;
        answer += n[cur];
    }
    return answer;
}