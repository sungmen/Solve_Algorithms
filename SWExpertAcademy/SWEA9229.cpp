#include <iostream>
#include <vector>
using namespace std;

int main()
{   
    int TC;
    cin >> TC;
    for(int test_case = 1; test_case <= TC; test_case++)
    {
        int N, M;
        cin >> N >> M;
        
        vector<int> v(N);
        for(int i = 0; i < N; i++)
        {
            cin >> v[i];
        }

        int max = -1;
        for (int i = 0; i < N-1; i++)
        {
            for (int j = i+1; j < N; j++)
            {
                if(v[i] + v[j] <= M)
                {
                    max = max < v[i] + v[j] ? v[i] + v[j] : max;
                }
                
            }
        }
        cout << "#" << test_case << " " << max << "\n";
    }

    return 0;
}