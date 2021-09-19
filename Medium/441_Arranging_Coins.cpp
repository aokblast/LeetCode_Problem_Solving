//Binary Search
//Runtime 0
//Memory Usage 6
class Solution {
public:
    int arrangeCoins(int n) {
        if(n <= 1)return 1;
        long long l = 1, r = n;
        while(l < r){
            long long mid = (l + r) >> 1;
            if((mid) * (mid + 1) / 2 <= n){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r - 1;
    }
};
