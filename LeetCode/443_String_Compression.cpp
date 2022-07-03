class Solution 
{
public:
    int compress(vector<char>& chars) 
    {
        queue<int> stk1;
        queue<char> stk2;
        char back = chars[0];
        int cnt = 1;
        for (int i = 1; i < chars.size(); i++) 
        {
            if (back == chars[i])
            {   
                cnt++;
            }
            else
            {
                stk1.push(cnt);
                stk2.push(back);
                cnt = 1;
                back = chars[i];
            }
        }
        stk1.push(cnt);
        stk2.push(back);
        int ans = 0;
        int index = 0;
        while (!stk1.empty())
        {
            if (stk1.front() == 1)
            {
                ans++;
                chars[index++] = stk2.front();
            }
            else
            {
                string str = to_string(stk1.front());
                ans += (str.size() + 1);
                chars[index++] = stk2.front();
                for (int i = 0; i < str.size(); i++)
                {
                    chars[index++] = str[i];
                }
            }
            stk1.pop();
            stk2.pop();
        }
        return ans;
    }
};