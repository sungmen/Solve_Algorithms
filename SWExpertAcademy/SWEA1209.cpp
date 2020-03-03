#include <iostream>
using namespace std;
#define ll  long long
#define endl    '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int Test_Case = 0; Test_Case < 10; Test_Case++) {
        int test_case;
        cin >> test_case;
        ll ARR[100][100];
        
        for (int f = 0; f < 100; f++) {
            for (int s = 0; s < 100; s++) {
                cin >> ARR[f][s];
            }
        }

        ll Max = 0;
        for (int f = 0; f < 100; f++) {
            ll sum = 0;
            ll sum2 = 0;
            for (int s = 0; s < 100; s++) {
                sum += ARR[f][s];
                sum2 += ARR[s][f];
            }
            Max = max(Max, max(sum, sum2));
        }
        ll sum = 0;
        ll sum2 = 0;
        for(int f = 0; f < 100; f++){
            sum += ARR[f][f];
            sum2 += ARR[99-f][99-f];
        }
        Max = max(Max, max(sum, sum2));
        cout << '#' << Test_Case + 1 << ' ' << Max << endl;
    }
    return 0;
}
