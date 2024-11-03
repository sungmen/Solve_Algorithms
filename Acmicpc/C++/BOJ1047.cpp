#include <bits/stdc++.h>
using namespace std;


void cal(int& x1, int& x2, int& y1, int& y2, int& nAllSum, vector<int> &vecC, vector<int> &cA, vector<int> &cB, int& answer)
{
    vector<int> tree;
    int nOutValue = 0;
    int nSum = 0;
    int nTreeSum = 2 * (x2 - x1 + y2 - y1);
    int n = vecC.size();
    for (int i = 0; i < n; i++)
    {
        int x = cA[i];
        int y = cB[i];
        int c = vecC[i];
        if (x < x1 || x > x2 || y < y1 || y > y2)
        {
            nOutValue += c;
            continue;
        }
        ++nSum;
        tree.emplace_back(-c);
    }
    if (nOutValue >= nTreeSum)
    {
        answer = min(answer, n - nSum);
        return;
    }
    if (nAllSum < nTreeSum)
    {
        return;
    }
    sort(tree.begin(), tree.end());
    for (auto it : tree)
    {
        --nSum;
        nOutValue -= it;
        if (nOutValue >= nTreeSum)
        {
            answer = min(answer, n - nSum);
            return;
        }
    }
}

void sol(int& answer)
{
    vector<int> vecA, vecB, vecC, cA, cB;
    int n;
    int nAllSum = 0;
    cin >> n;
    answer = n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vecA.emplace_back(a);
        cA.emplace_back(a);
        vecB.emplace_back(b);
        cB.emplace_back(b);
        vecC.emplace_back(c);
        nAllSum += c;
    }
    sort(vecA.begin(), vecA.end());
    sort(vecB.begin(), vecB.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                for (int l = k; l < n; l++)
                {
                    cal(vecA[i], vecA[j], vecB[k], vecB[l], nAllSum, vecC, cA, cB, answer);
                }
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int answer = 41;
    sol(answer);
    cout << answer;
    return 0;
}
