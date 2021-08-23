//
//Runtime 0
//Memory Usage 6
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int ans = 0;
        while(left <= right){
            int mid = (left + right) >> 1;
            long long val = 1L * mid * mid;
            if(val < x){
                ans = mid;
                left = mid + 1;
                
            }else if(val > x){
                right = mid - 1;
            }else{
                return mid;
            }
        }
        return ans;
    }
};
