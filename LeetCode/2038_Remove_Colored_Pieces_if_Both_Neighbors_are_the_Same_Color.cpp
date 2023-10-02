class Solution 
{
public:
    void calString(int &a, int &b, int &resA, int &resB, char cur)
    {
            if (cur == 'A')
            {
                resB += (b > 2 ? b - 2 : 0);
                b=0;
                a++;
            }
            else
            {
                resA += (a > 2 ? a - 2 : 0);
                a = 0;
                b++;
            }
    }
    bool winnerOfGame(string colors) 
    {
        int a = 0, b = 0;
        int resA = 0, resB = 0;
        for (auto c : colors)
        {
            calString(a,b,resA,resB,c);
        }
        calString(a,b,resA,resB,(colors.back()=='A'?'B':'A'));
        return resA > resB ? 1 : 0;
    }
};