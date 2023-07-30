// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution 
{
public:
    int rand10() 
    {
        int res = INT_MAX;

        while (res > 40)
        {
            res = (rand7() - 1) * 7 + rand7();
        }
        return res % 10 +1;
    }
};