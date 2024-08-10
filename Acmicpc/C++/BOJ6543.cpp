#include <bits/stdc++.h>
using namespace std;

class Tarjan
{
private:
    int n = 0;
    int m = 0;
    int visitCnt = 0;
    int sccCnt = 0;
    vector<bool> checked;
    vector<int> dis;
    vector<int> scId;
    vector<int> out;
    vector<int> ans;
    vector<int> vec[5001];
    vector<vector<int>> tarVec;
    stack<int> stk;

public:

    void print()
    {
        sort(ans.begin(), ans.end());

        for (auto &i : ans)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }

    void outSet()
    {
        out.resize(sccCnt, 0);

        for (int i = 1; i <= n; i++)
        {
            for (auto n : vec[i])
            {
                if (scId[i] == scId[n]) { continue; }

                out[scId[i]] ++;
            }
        }

        for (int i = 0; i < sccCnt; i++)
        {
            if (0 != out[i]) { continue; }

            for (auto n : tarVec[i])
            {
                ans.push_back(n);
            }
        }
    }

    int tarjan(int c)
    {
        stk.push(c);
        dis[c] = ++visitCnt;
        int l = dis[c];

        for (auto n : vec[c])
        {
            if (true == checked[n]) { continue; }

            if (0 == dis[n])
            {
                l = min(l, tarjan(n));
            }
            else
            {
                l = min(l, dis[n]);
            }
        }

        if (l != dis[c]) { return l; }

        bool bCheck = true;
        while (true == bCheck)
        {
            int tp = stk.top();
            stk.pop();
            scId[tp] = sccCnt;
            checked[tp] = true;
            tarVec[sccCnt].push_back(tp);

            if (c == tp)
            {
                bCheck = false;
            }
        }

        sort(tarVec[sccCnt].begin(), tarVec[sccCnt].end());
        ++sccCnt;

        return l;
    }

    void run()
    {
        for (int i = 1; i <= n; i++)
        {
            if (false == dis[i])
            {
                tarjan(i);
            }

        }

        outSet();
        print();
    }

    bool init()
    {
        cin >> n;
        if (0 == n) { return false; }

        tarVec.resize(n + 1, {});
        scId.resize(n + 1, 0);
        dis.resize(n + 1, 0);
        checked.resize(n + 1, false);

        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            vec[a].push_back(b);
        }

        run();

        return true;
    }


};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    bool bChk = true;
    while (true == bChk)
    {
        Tarjan scc;
        bChk = scc.init();
    }
    return 0;
}
