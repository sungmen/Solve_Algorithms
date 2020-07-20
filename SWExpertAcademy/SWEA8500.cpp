#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for(int test_c = 1; test_c <= T; test_c++)
    {
        int N;
        scanf("%d", &N);
        vector<int> v(N);
        int ans = N;
        for(int i = 0; i < N; i++)
        {
            cin >> v[i];
        }   
        sort(v.begin(), v.end());
        ans += v[0];
        ans += v[N-1];
        for (int i = 1; i < N; i++)
        {
            ans += v[i];
        }
        printf("#%d %d\n", test_c, ans);
    }
    return 0;
}