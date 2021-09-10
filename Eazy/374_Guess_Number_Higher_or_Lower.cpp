//Binary Search
//Runtime 0
//Memory Usage 6
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long left = 1, right = n;
        while(left <= right){
            int mid = (left + right) >> 1;
            int g = guess(mid);
            if(!~g){
                right = mid - 1;
            }else if(g){
                left = mid + 1;
            }else{
                return mid;
            }
        }
        return 0;
    }
};
