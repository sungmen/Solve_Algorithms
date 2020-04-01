#include <iostream>
using namespace std;
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        for (int test_case = 1; test_case <= 10; test_case++) {
                int n;
                cin >> n;
            	string str;
                int sum = 0;
            	cin >> str;
            	while(n--) {
                    if (n % 2 == 0) {
                        sum += (int)str[n] - 48;
                    }
                }
                cout << "#" << test_case << " " << sum << endl;
        }

        return 0;
}
