class Solution 
{
public:
    int arr[1001];

    int find(int n)
    {
        return n == arr[n] ? n : find(arr[n]);
    }

    void merge(int a, int b)
    {
        arr[find(a)] = arr[find(b)];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        for (int i = 0; i < 1001; i++)
            arr[i] = i;
        for (auto edge : edges)
        {
            int a = find(edge[0]);
            int b = find(edge[1]);
            if (a == b) return edge;
            merge(edge[0], edge[1]);
        }
        return {};
    }
};