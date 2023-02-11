class Solution {
public:
    string sum(string str1, string str2)
    {
        int n1 = str1.size(), n2 = str2.size();
        int upper = 0;
        string res = "";
        n1--;
        n2--;
        while (n1 >= 0 && n2 >= 0)
        {
            int num1 = str1[n1] - '0';
            int num2 = str2[n2] - '0';
            int sum = upper + num1 + num2;
            upper = (sum >= 10);
            sum %= 10;
            res += (sum + '0');
            n1--;
            n2--;
        }
        if (n1 == -1 && n2 == -1)
        {
            if (upper)
                res += '1';
            reverse(res.begin(), res.end());
            return res;
        }
        if (n1 == -1)
            while (n2 >= 0)
            {
                int num = str2[n2] - '0';
                int sum = upper + num;
                upper = (sum >= 10);
                sum %= 10;
                res += (sum + '0');
                n2--;
            }
        if (n2 == -1)
            while (n1 >= 0)
            {
                int num = str1[n1] - '0';
                int sum = upper + num;
                upper = (sum >= 10);
                sum %= 10;
                res += (sum + '0');
                n1--;
            }
        
        if (upper)
            res += '1';
        reverse(res.begin(), res.end());
        return res;
    }

    string multiply(string num1, string num2) {
        if ("0" == num1 || "0" == num2) return "0";
        string str = "0";
        if (num1.size() < num2.size())
            swap(num1, num2);
        for (int i = 0; i < num2.size(); i++)
        {
            string next = num1;
            next += string(num2.size()-1-i, '0');
            int upper = 0;
            string mul = "";
            for (int j = next.size() - 1; j >= 0; j--)
            {
                int n1 = next[j] - '0';
                int n2 = num2[i] - '0';
                int mu = n1 * n2;
                int munext = mu / 10;
                mu %= 10;
                munext += ((mu + upper) / 10);
                mu = ((mu + upper) % 10);
                mul += mu + '0';
                upper = munext;
            }
            if (upper > 0)
            {
                string ustr = to_string(upper);
                for (auto k : ustr)
                {
                    mul += k;
                }
            }
            reverse(mul.begin(), mul.end());
            str = sum(str, mul);
        }
        return str;
    }
};