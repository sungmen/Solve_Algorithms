#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int test_case  = 1; test_case <= 10; test_case++) {
        int n;
        cin >> n;
        vector<vector<char> > vi(8, vector<char>(8));
        for(int i = 0; i < 8; i++) 
            for (int j = 0; j < 8; j++) 
                cin >> vi[i][j];
                
		    int cnt = 0;
        for(int i = 0; i < 8; i++) {
            for (int j = 0; j < 8 - n + 1; j++) {
                int left = j, right = n - 1 + j;
                int chk = 1;
                
                while(left <= right) {
                    if (vi[i][left] != vi[i][right]){
                        chk = 0;
                        break;
                    }
                    left++; right--;
                }
                if(chk != 0)
                    cnt++;
                chk = 1;
                
                left = j, right = n - 1 + j;
                while(left <= right) {
                    if (vi[left][i] != vi[right][i]){
                        chk = 0;
                        break;
                    }
                    left++; right--;
                }
                if(chk != 0)
                    cnt++;
            }
        }
        
        cout << "#" << test_case << " " << cnt << endl;
    }
    
    return 0;
}
