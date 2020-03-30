#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int test_case = 1; test_case <= 10; test_case++) {
     	int cnt = 0;
        int test_;
        cin >> test_;
        vector<int> v(test_);
        for (int i = 0; i < test_; i++) 
            cin >> v[i];
        
        for (int i = 2; i < test_-1; i ++) {
         	if (v[i] > v[i-1] && v[i] > v[i-2] && v[i] > v[i+1] && v[i] > v[i+2]) {
            	cnt += min(min(v[i]-v[i-1], v[i]-v[i-2]), min(v[i]-v[i+1], v[i]-v[i+2]));
            }
        }
    	cout << "#" << test_case <<  " " << cnt << endl;
    }
    return 0;
}
