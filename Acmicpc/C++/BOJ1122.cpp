#include <bits/stdc++.h>
using namespace std;

constexpr int MAXNUM = 1e5;
constexpr int FAIL = -1;
constexpr int ZERO = 0;

int sol(const int &a, const int &b, const int &k)
{
    bool bAZero = (0 == a);
    bool bKZero = (0 == k);
    if (true == bAZero) { return ZERO; }
    if (true == bKZero) { return FAIL;}

    long long nA = 0;
    long long nB = 0;
    for (int i = 1; i <= MAXNUM; i++)
    {
        nA = (1 == (i % 2) ? (long long)i * a : nA);
        nB = (0 == (i % 2) ? (long long)i * b : nB);
        long long nSum = nA + nB;
        long long nNum = (long long)i * k;
        if (nNum > nSum || nNum < a) { continue; }
        if (0 != ((nSum - nNum) % 2)) { continue; }

        return i;
    }

    return FAIL;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int a, b, k;
    cin >> a >> b >> k;

    int ans = sol(a, b, k);
    cout << ans;

    return 0;
}
