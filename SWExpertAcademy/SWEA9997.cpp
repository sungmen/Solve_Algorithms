#include <iostream>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    
    for (int test_case = 1; test_case <= t; test_case++)
    {
		int h, m, angle;
        cin >> angle;
        angle *= 2;
        h = angle / 60;
        m = angle % 60;
        cout << "#" << test_case << " " << h << " " << m << "\n";
    }

    return 0;
}