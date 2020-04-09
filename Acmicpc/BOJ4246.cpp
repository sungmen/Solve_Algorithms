#include <iostream>
#include <vector>

using namespace std;

int main() {

    while(1) {
        int n = 1;
        scanf("%d", &n);
        if(!n)
            break;
        string str;
        cin >> str;
        int str_size = str.size()/n;
        vector<vector<char> >v(str_size, vector<char>(n));

        for(int i = 0; i < str_size; i++) {
            for(int j = 0; j < n; j++) {
                if(i%2)
                    v[i][n-j-1] = str[n*i+j];
                else
                    v[i][j] = str[n*i+j];
            }
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < str_size; j++) {
                cout << v[j][i];
            }
        cout<<'\n';

    }

    return 0;
}