#include <iostream>
#include <bitset>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		const int K = sizeof(unsigned long) * 8;
		int N;
		cin >> N;

		string bi = bitset<K>(N).to_string();
		for (int i = 0; i < K; i++)
		{
		    if (bi[i] == '1')
		    {
		        Answer++;
		    }
		}
		
		
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}