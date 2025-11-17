#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    fast
    int n, k;
    cin >> n >> k;
    ordered_set oSet;
    for (int i = 1; i <= n; i++)
        oSet.insert(i);
    int nK = 0;
    cout << '<';
    while(n--)
    {
        nK += k - 1;
        nK %= (n + 1);
        cout << *(oSet.find_by_order(nK));
        oSet.erase(oSet.find_by_order(nK));
        if (n != 0)
            cout << ", ";
    }
    cout << '>';

    return 0;
}
