class Solution {
public:
    int largestInteger(int num) {
        vector<int> odd, even;
        string str = to_string(num);
        bool chk = (str[0] - '0') % 2;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] % 2 == 0)
                odd.push_back(str[i] - '0');
            else
                even.push_back(str[i] - '0');
        }
        sort(odd.begin(), odd.end(), greater<>());
        sort(even.begin(), even.end(), greater<>());
        int result = 0;
        int ol = 0, el = 0;
        for (int i = 0; i < str.size(); i++)
        {
            result *= 10;
            if ((str[i] - '0') % 2 == 0)
            {
                result += (odd[ol++]);
            }
            else
            {
                result += (even[el++]);
            }
        }
        return result;
    }
};