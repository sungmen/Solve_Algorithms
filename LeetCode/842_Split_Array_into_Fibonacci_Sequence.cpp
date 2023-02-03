class Solution 
{
public: 
    vector<int> splitIntoFibonacci(string num) {
        int nSize = num.size();
        for (int i = 1; i < nSize - 2; i++)
        {
            string sTmpl = num.substr(0, i);
            if (sTmpl.size() > 1 && '0' == sTmpl[0]) break;
            long long tmpl = stol(sTmpl);
            if (tmpl > INT_MAX) break;
            int num1 = tmpl;
            for (int j = i; j < nSize - 1; j++)
            {
                string sTmpr = num.substr(i, j - i + 1);
                if (sTmpr.size() > 1 && '0' == sTmpr[0]) break;
                long long tmpr = stol(sTmpr);
                if (tmpr > INT_MAX) break;
                int num2 = tmpr;
                vector<int> v;
                v.push_back(num1);
                v.push_back(num2);
                int r = 1, k = j + 1;
                bool chk = true;
                while (nSize > k)
                {
                    long long lSum = (long long)v[r - 1] + (long long)v[r];
                    if (lSum > INT_MAX)
                    {
                        chk = 0;
                        break;
                    }
                    string sSum = to_string(lSum);
                    int nSum = sSum.size();
                    if (k + nSum > nSize)
                    {
                        chk = 0;
                        break;
                    }
                    string curStr = num.substr(k, nSum);
                    long long curNum = stol(curStr);
                    k = k + nSum;
                    if (curNum != (int)lSum)
                    {
                        chk = 0;
                        break;
                    }
                    v.push_back(curNum);
                    r++;
                }
                if (chk)
                    return v;
            }
        }

        return {};
    }
};