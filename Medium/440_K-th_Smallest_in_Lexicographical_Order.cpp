//
//Runtime 0
//Memory Usage 5.9
class Solution {
public:
    int findKthNumber(int n, int k) {
        int ans = 1;
        --k;
        while(k){
            long long s = 0, l = ans, r = ans + 1;
            while(l <= n){
                s += min((long long)n + 1, r) - l;
                l *= 10, r *= 10;
            }
            if (s <= k) {
                ++ans;
                k -= s;
            } else {
                 ans *= 10;
                --k; 
            }  
        }
        return ans;
    }
};
