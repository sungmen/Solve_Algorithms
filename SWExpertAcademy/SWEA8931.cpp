#include<iostream>
#include<stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> s;

    int test_case;
    cin >> test_case;
    for (int t = 1; t <= test_case; t++) {
        int test_case2;
        cin >> test_case2;
        for (int t2 = 0; t2 < test_case2; t2++) {
            int num;
            cin >> num;
            if (num == 0) {
                s.pop();
            } else 
                s.push(num);
        }
        int sum = 0;
        while(!s.empty()) {
            sum += s.top();
            s.pop();
        }
        cout << '#' << t << ' ' << sum << endl;
    }

    return 0;
}
