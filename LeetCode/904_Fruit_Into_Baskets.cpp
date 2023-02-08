class Solution 
{
public:
    int totalFruit(vector<int>& fruits) 
    {
        int ans = 1, f = fruits[0], fn = 1, fm = 1, s = -1, sn = 0, sm = 0;
        for (int i = 1; i < fruits.size(); i++)
        {
            if (fruits[i] == f)
            {
                fn++;
                fm++;
            }
            else if (fruits[i] == s)
            {
                sn++;
                swap(f, s);
                swap(fn, sn);
                sm = fm;
                fm = 1;
            }
            else
            {
                sm = sn = fm;
                fn = fm = 1;
                s = f;
                f = fruits[i];
            }
            int n = fn + sn;
            if (ans < n)
                ans = n;
        }
        return ans;
    }
};