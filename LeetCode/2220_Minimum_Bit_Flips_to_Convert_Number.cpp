class Solution 
{
public:
    int minBitFlips(int start, int goal) 
    {
        bitset<80> b1(start);
        bitset<80> b2(goal);
        
        int cnt = 0;
        for (int i = 0; i < 80; i++)
        {
            if (b1[i] ^ b2[i])
            {
                cnt++;
            }
        }
        
        return cnt;
    }
};