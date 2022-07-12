class Solution 
{
public:
    string reverseVowels(string s) 
    {
        vector<int> v;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A'|| s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                v.push_back(i);
            }
        }
        for (int i = 0; i < v.size() / 2; i++)
        {
            swap(s[v[i]], s[v[v.size() - i - 1]]);
        }
        return s;
    }
};