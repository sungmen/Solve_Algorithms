class Solution 
{
public:
    string gcdOfStrings(string str1, string str2) 
    {
        string str = str1 + str2;
        string rev = str2 + str1;
        if (str == rev)
        {
            return str1.substr(0, gcd(str1.size(), str2.size()));
        }

        return "";
    }
};