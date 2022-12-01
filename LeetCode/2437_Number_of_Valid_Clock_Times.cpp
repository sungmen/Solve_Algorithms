class Solution {
public:
    int countTime(string time) {
        int a = 1, b = 1;
        if ('?' == time[0])
        {
            if ('?' == time[1])
            {
                a = 24;
            }
            else if ('5' <= time[1])
            {
                a = 2;
            }
            else
            {
                a = 3;
                if ('4' == time[1] && !('0' == time[3] && '0' == time[4]))   
                a = 2;
            }
        }
        else if ('?' == time[1])
        {
            if ('2' == time[0])
                a = 4;
            else
                a = 10;
        }
        if ('?' == time[3])
            b *= 6;
        if ('?' == time[4])
            b *= 10;
        return a * b;
    }
};