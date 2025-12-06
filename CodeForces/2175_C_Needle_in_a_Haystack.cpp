#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#define endl "\n"

string sol()
{
    string str1, str2;
    cin >> str1 >> str2;
    
    vector<int> v1(26), v2(26);
    for (auto it : str1) {v1[it - 'a']++;}
    for (auto it : str2) {v2[it - 'a']++;}
    bool bImPossible = false;
    string ans = "";
    vector<string> v3;
    int k = str1[0] - 'a';
    int start = 0;
    for (int i = 1; i < str1.size(); i++)
    {
        if (str1[i] - 'a' >= k)
        {
            v3.push_back(str1.substr(start,i-start));
            start = i;
            k = str1[i] - 'a';
        }
    }
    v3.push_back(str1.substr(start,str1.size()-start));
    for (int i = 0; i < 26; i++)
    {
        if (v1[i] > v2[i])
        {
            return "Impossible";
        }
        else
        {
            ans += string(v2[i] - v1[i], i + 'a');
        }
    }
    int idx = 0;
    int t = ans.size();
    int ct = 0; //v3 count;
    while (idx < t && ct < v3.size())
    {
        if (ans[idx] < v3[ct][0])
        {
            idx++;   
        }
        else
        {
            ans.insert(idx, v3[ct++]);
            idx  += v3[ct-1].size();
            t += v3[ct-1].size();
        }
    }
    while (ct < v3.size())
    {
        ans += v3[ct++];
    }
  
    return ans;
}

int main() {
    fast
    int tc;
    for(cin>>tc; tc--;)
    {
        cout << sol() << endl;
    }
}