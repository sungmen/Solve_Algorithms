#include <bits/stdc++.h>
using namespace std;

// merge
void merge(vector<int> &v, vector<int> &arr, long long &answer, int l, int m, int r)
{
    int idxLeft = l;
    int idxRight = m + 1;
    int idxMerge = l;

    while (idxLeft <= m && idxRight <= r)
    {
        if (v[idxLeft] <= v[idxRight])
        {
            arr[idxMerge++] = v[idxLeft++];
        }
        else
        {
            arr[idxMerge++] = v[idxRight++];
            answer += m + 1 - idxLeft;
        }
    }

    for (idxLeft; idxLeft <= m; idxLeft++)
    {
        arr[idxMerge++] = v[idxLeft];
    }

    for (idxRight; idxRight <= r; idxRight++)
    {
        arr[idxMerge++] = v[idxRight];
    }    

    for (int i = l; i <= r; i++)
    {
        v[i] = arr[i];
    }
}

// merge sort
void mergeSort(vector<int> &v, vector<int> &arr, long long &answer, int l, int r)
{
    if (l >= r) { return; }
    int m = (l + r) / 2;
    mergeSort(v, arr, answer, l, m);
    mergeSort(v, arr, answer, m + 1, r);
    merge(v, arr, answer, l, m, r);
}

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n; 
    long long answer = 0;
    vector<int> v;
    vector<int> arr(500001);

    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    mergeSort(v, arr, answer, 0, n - 1);

    cout << answer;

    return 0;
}
