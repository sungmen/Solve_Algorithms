class Solution 
{
public:
    int clumsy(int n) 
    {
        int i = 0;
        vector<int> v;
        v.push_back(n--);
        int s = 0;
        while (n)
        {
            switch(i)
            {
            case 0:
                s = v.back() * n;
                v.pop_back();
                v.push_back(s);
                break;
            case 1:
                s = v.back() / n;
                v.pop_back();
                v.push_back(s);
                break;
            case 2:
                v.push_back(n);
                break;
            case 3:
                v.push_back(-n);
                break;
            }
            n--;
            i = (++i > 3 ? 0 : i);
        }
        int answer = 0;
        for (auto c : v)
            answer += c;
        return answer;
    }
};