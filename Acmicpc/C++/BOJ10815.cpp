#include <vector>
#include <iostream>
#include <map>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    map<int, int> m;
    for(int i = 0; i < N; i++) 
    {
        int num;
        cin >> num;
        m[num] = 1;
    }

    int M;
    cin >> M;
    vector<int> mArr(M, 0);
    for (int i = 0; i < M; i++) 
    {
        int num;
        cin >> num;
        if (m.find(num) != m.end())
        {
            mArr[i] = 1;
        }
        else
        {
            mArr[i] = 0;
        }
    }

    for (vector<int>::iterator iter = mArr.begin(); iter != mArr.end(); iter++)
    {
        cout << *iter << ' ';
    }

    return 0;
}