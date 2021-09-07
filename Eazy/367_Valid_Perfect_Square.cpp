//Binary Search
//Runtime 0
//Memory Usage 5.9
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 0, r = num;
        while(l <= r){
            long long mid = (l + r) >> 1;
            if(mid * mid > num){
                r = mid - 1;
            }else if(mid * mid == num){
                return true;
            }else{
                l = mid + 1;
            }
        }
        return false;
    }
};
