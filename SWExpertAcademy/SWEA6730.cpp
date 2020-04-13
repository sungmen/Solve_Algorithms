#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    for(int t = 1; t <= test_case; t++) {
        int test_n;
        cin >>test_n;
        int up=0, down=0;
        int num;
        cin >> num;
        int temp = num;
        for(int i = 1; i < test_n; i++) {
            cin >> num;
            if(temp < num){
                temp = num - temp;
                up = max(up, temp);
            } else if (temp > num) {
                temp = temp - num;
                down = max(down, temp);
            }
            temp = num;
        }
        cout << "#" << t << " " << up << " " << down << "\n";
    }

    return 0;
}