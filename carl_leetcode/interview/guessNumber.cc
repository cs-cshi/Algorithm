/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guess(int);

    int guessNumber(int n)
    {
        int left = 0;
        int right = n;
        while (left <= right)
        {
            int mid = ((right - left) >> 1) + left;
            int guessResult = guess(mid);
            if (mid == -1)
                right = mid - 1;
            else if(mid == 1)
                left = mid + 1;
            else
                return mid;
        }
    }
};