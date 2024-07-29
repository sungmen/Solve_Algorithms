#include <bits/stdc++.h>
using namespace std;

class SCC
{
public:
    int v = 0;
    int e = 0;
    int cnt = 1;
    vector<vector<int>> arr;
    vector<vector<int>> answer;
    vector<int> dsn;
    vector<bool> check;
    stack<int> stk;

    int dfs(int idx)
    {
        dsn[idx] = cnt++;
        stk.push(idx);

        int res = dsn[idx];
        
        for (auto i : arr[idx])
        {
            if (0 == dsn[i])
            {
                res = min(res, dfs(i));
            }
            else if (false == check[i])
            {
                res = min(res, dsn[i]);
            }
        }

        if (res != dsn[idx]) { return res; }

        vector<int> tarjan;

        bool chk = true;
        while (false != chk && false == stk.empty())
        {
            int stkTop = stk.top();
            tarjan.push_back(stkTop);
            stk.pop();
            check[stkTop] = true;
            if (stkTop != idx) { continue; }
            chk = false;
        }

        answer.push_back(tarjan);

        return res;
    }

    void search()
    {
        for (int i = 1; i <= v; i++)
        {
            if (0 != dsn[i]) { continue; }
            dfs(i);
        }

        for (int i = 0; i < answer.size(); i++)
        {
            sort(answer[i].begin(), answer[i].end());
        }
        sort(answer.begin(), answer.end());
    }

    void print()
    {
        cout << answer.size() << '\n';
        for (auto i : answer)
        {
            for (auto j : i)
            {
                cout << j << ' ';
            }
            cout << -1 << '\n';
        }
    }

    void init()
    {
        arr.resize(v + 1);
        dsn.resize(v + 1);
        check.resize(v + 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    SCC scc;
    cin >> scc.v >> scc.e;
    scc.init();
    int a, b;
    for (int i = 0; i < scc.e; i++)
    {
        cin >> a >> b;
        scc.arr[a].push_back(b);
    }
    scc.search();
    scc.print();
    return 0;
}
