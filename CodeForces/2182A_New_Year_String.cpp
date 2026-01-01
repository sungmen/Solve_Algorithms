#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#define endl "\n"

void sol()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool b2025 = false;
    bool b2026 = false;
    for (int i = 0; i < n-3; i++)
    {
        if (s[i] == '2' && s[i+1] == '0' && s[i+2] == '2' && s[i+3] == '5')
        {
            b2025 = true;
        }
        if (s[i] == '2' && s[i+1] == '0' && s[i+2] == '2' && s[i+3] == '6')
        {
            b2026 = true;
        }
    }
    if (b2026) cout << '0' << endl;
    else if (b2025) cout << '1' << endl;
    else cout << '0' << endl;
}

int main() {
    fast
    int tc;
    for(cin>>tc; tc--;)
    {
        sol();
    }
}