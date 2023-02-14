class Solution 
{
public:
    vector<int> addToArrayForm(vector<int>& num, int k) 
    {
        vector<int> res;
        string sum = "";
        for (int i = 0; i < num.size(); i++)
        {
            sum += (num[i] + '0');
        }
        string p = to_string(k);
        if (sum.size() < p.size())
            swap(sum, p);
        cout << sum << ' ' << p;
        int upper = 0;
        int ssize = sum.size() - 1;
        int psize = p.size() - 1;
        while (ssize >= 0)
        {
            int t = upper + (sum[ssize] - '0') + (psize >= 0 ? p[psize] - '0' : 0);
            int cur = t % 10;
            res.insert(res.begin(), cur);
            upper = t / 10;
            ssize--;
            psize--;
        }
        if (upper > 0)
            res.insert(res.begin(), upper);
        return res;
    }
};