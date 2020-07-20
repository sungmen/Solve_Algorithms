#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<vector<bool> > &vb, int x, int y) 
{
	int diff = 0;
    for (int i = x - 1; i >= 0; i--) 
    {
    	diff++;
        if (vb[y][i] || (y - diff >= 0 && vb[y - diff][i]) || (y + diff < vb.size()) && vb[y + diff][i])
        {
        	return false;
        }
    }
    return true;
}

int dfs(vector<vector<bool> > &vb, int x) 
{
	if (x == vb.size())
    {
        return 1;
    }
    int cnt = 0;
    for (int i = 0; i < vb.size(); i++)
    {
        if (isValid(vb, x, i))
		{
        	vb[i][x] = true;
            cnt += dfs(vb, x + 1);
            vb[i][x] = false;
        }
    }
	return cnt;
}
            
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N;
        cin >> N;
        vector<vector<bool> >vb(N, vector<bool>(N, false));
		cout << "#" << test_case << " " << dfs(vb, 0) << "\n";
	}
	return 0;
}