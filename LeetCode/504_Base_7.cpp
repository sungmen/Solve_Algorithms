class Solution 
{
public:
    string convertToBase7(int num) 
    {
        if (0 == num) return "0";
        string str = "";
        int m = abs(num);
        while(m)
        {
            int n = m % 7;
            str += n + '0';
            m /= 7;
        }
        if (num < 0) str += '-';
        reverse(str.begin(), str.end());
        return str;    
    }
};