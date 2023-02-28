class Solution 
{
public:
    int minFlips(int a, int b, int c) 
    {
        bitset<30> ba(a), bb(b), bc(c);
        int cnt = 0;
        for (int i = 0; i < 30; i++)
        {
            if (bc[i])
            {
                cnt += !(ba[i] || bb[i]);
            }
            else
            {
                cnt += ba[i];
                cnt += bb[i];
            }
        }
        return cnt;
    }
};