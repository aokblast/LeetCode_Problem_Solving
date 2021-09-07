//
//Runtime 0
//Memory Usage 5.9 
class Solution {
public:
    int jiecheng(int n){
        int ans = 1;
        for(int i = 1; i <= n - 1; ++i){
            ans *= (10 - i);
        }
        
        return ans * 9;
    }
    int countNumbersWithUniqueDigits(int n) {
        int ans = 1;
        for(int i = 1; i <= n; ++i){
            ans += jiecheng(i);
        }
        return ans;
    }
};
