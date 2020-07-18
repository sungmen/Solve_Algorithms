#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        vector<int> v(12, 4);
        v[10] = 16;
		int N;
        cin >> N;
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
			int number;
            cin >> number;
            v[number]--;
            sum += number;
		}
        int cnt = 21 - sum;
        int upcnt = 0;
        for (int i = cnt; i > 1; i--)
        {
            upcnt += v[i];
        }
        int docnt = 0;
        for (int i = cnt+1; i <= 11; i++ )
        {
            docnt += v[i];
        }
        if(upcnt > docnt)
        {
            cout << "#" << test_case <<  " GAZUA " << "\n";
        }
        else
        {
            cout << "#" << test_case <<  " STOP" << "\n";    
        }
    }
	return 0;
}