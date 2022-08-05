class Solution 
{
public:
    string minimizeResult(string expression) 
    {
        int i = 0;
        while (expression[++i] != '+');
        vector<long long> lv, rv, lmul, rmul;
        lv.push_back(1);
        lmul.push_back(1);
        rv.push_back(1);
        rmul.push_back(1);
        int l = 0;
        long long lvalue = 0;
        while (l < i)
        {
            lvalue *= 10;
            lvalue += expression[l++] - '0';
            lv.push_back(lvalue);
        }
        l = i - 1;
        long long upper = 1;
        lvalue = 0;
        while (l >= 0)
        {
            lvalue += (expression[l--] - '0') * upper;
            upper *= 10;
            lmul.push_back(lvalue);
        }        
        int r = i + 1;
        upper = 1;
        long long rvalue = 0;
        while (r < expression.size())
        {
            rvalue *= 10;
            rvalue += expression[r++] - '0';
            rmul.push_back(rvalue);
        }
        rvalue = 0;
        r = expression.size() - 1;
        while (r > i)
        {
            rvalue += (expression[r--] - '0') * upper;
            upper *= 10;
            rv.push_back(rvalue);
        }
        int lvsize = lv.size(), rvsize = rv.size();
        string res = "(" + expression + ")";
        long long resll = lv[lvsize-1] + rv[rvsize-1];
        int iup = 0;
        for (int i = lvsize - 1; i > 0; i--)
        {
            long long curll = 0;
            int rup = 0;
            for (int j = rvsize - 1; j > 0; j--)
            {
                curll = lmul[i] + rmul[j];
                curll *= lv[iup];
                curll *= rv[rup];
                if (resll > curll)
                {
                    string ltp = (iup == 0 ? "" : to_string(lv[iup]));
                    string rtp = (rup == 0 ? "" : to_string(rv[rup]));
                    res = ltp + "(" + to_string(lmul[i]) + "+" + to_string(rmul[j]) + ")" + rtp;
                    resll = curll;
                }
                rup++;
            }
            iup++;
        }
        return res;
    }
};