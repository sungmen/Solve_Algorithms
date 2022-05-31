class Solution 
{
public:
    string maximumBinaryString(string binary) 
    {
        int n = binary.size(), l = 0, r = n - 1;
        while (l < n && '1' == binary[l]) l++;
        if (l == n) return binary;
        while (r >= 0 && '1' == binary[r]) r--;
        if (r == -1) return string(n-1, '1') + '0';
        string ans = string(l, '1');
        string back = string(n-r-1, '1');
        string tmp = "";
        int one = 0;
        for (int i = l; i <= r; i++) 
        {
            if ('1' == binary[i]) one++;
        }
        return ans + string(r-l-one, '1') + '0' + string(one, '1') + back;
    }
};