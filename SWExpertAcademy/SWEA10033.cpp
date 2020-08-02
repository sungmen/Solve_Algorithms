#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        long long sum = 0;
        int cnt = 0;
        for (int j = 0; j < str.length(); j++)
        {
            if(str[j]== 'B')
            {
                cnt++;
            }
            if(str[j] == 'W')
            {
                sum += cnt;
            }
        }
        cout << "#" << i+1 << " " << sum << "\n";
    }

}