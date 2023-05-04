class Solution 
{
public:
    string predictPartyVictory(string senate) 
    {
        int r = -1, d = -1;
        while (true)
        {
            r++;
            while (senate.size() > r && senate[r] != 'R') r++;
            if (senate.size() <= r) return "Dire";
            d++;
            while (senate.size() > d && senate[d] != 'D') d++;
            if (senate.size() <= d) return "Radiant";
            if (r < d)
                senate += 'R';
            else
                senate += 'D';
        }
        return "";
    }
};