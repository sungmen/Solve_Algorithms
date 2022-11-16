/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution 
{
public:
    int guessNumber(int n) 
	{
        long long l = 0, r = n;
        while (l <= r)
        {
            long long mid = (l + r) / 2;
            int tmp = guess(mid);
            switch(tmp)
            {
            case -1:
            {
                r = mid - 1;
                break;
            }
            case 1:
            {
                l = mid + 1;
                break;
            }
            case 0:
            {
                return mid;
            }
            }
        }
        return -1;
    }
};