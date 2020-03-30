#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int test_case = 1; test_case <= 10; test_case++) {
        int minus = 0;
        int box_c;
        cin >> box_c;
        vector<int> v(100);

        for (int i = 0; i < 100; i++) 
            cin >> v[i];
        
        for (int i = 0; i < box_c; i++) {
            sort(v.begin(), v.end());
            v[0]++;v[99]--;
        }
        sort(v.begin(), v.end());
        cout << "#" << test_case << " " << v[99]-v[0] << "\n";
    }

    return 0;
}
