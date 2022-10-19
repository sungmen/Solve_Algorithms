class Solution 
{
public:
    string countAndSay(int n) 
    {
        string str = "1";
        for (int i = 2; i <= n; i++)
        {
            string tmp = "";
            
            int j = 0;
            char ch = ' ';
            int cnt = 0;
            char cur = ' ';
            while (j < str.size())
            {
                cur = str[j++];
                if (ch != cur)
                {
                    if (ch != ' ')
                    {
                        tmp += to_string(cnt);
                        tmp += ch;
                    }
                    cnt = 1;
                }
                else
                {
                    cnt ++;
                }
                ch = cur;
            }
            tmp += to_string(cnt);
            tmp += cur;
            str = tmp;
        }
        return str;
    }
};