#include <iostream>

using namespace std;

#define ll long long

int main() 
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int start, dest;
    ll n = 1, cnt = 0;
    cin >> start >> dest;
    ll dis = dest - start;
    
    while(1)
    {
        ll value = n * n;
        if (value == dis)
        {
            cout << 2 * n - 1;
            return 0;
        }
        else if (value > dis)
        {
            if (((n * n) + (n - 1) * (n - 1)) / 2 < dis)
            {
                cout << 2 * n - 1;
            }
            else 
            {
                cout << 2 * (n - 1);
            }
            return 0;
        }
        n++;
    }
    
    return 0;
}