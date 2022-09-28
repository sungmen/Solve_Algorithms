class Solution 
{
public:
    string removeDigit(string number, char digit) 
    {
        map<string, int> m;
        string result = "";
        for (int i = 0; i < number.size(); i++)
        {
            if (number[i] == digit)
            {
                string tmp = number.substr(0, i) + number.substr(i + 1, number.size());
                m[tmp] = 1;
            }
        }
        auto it = m.end();
        it--;
        return it->first;
    }
};