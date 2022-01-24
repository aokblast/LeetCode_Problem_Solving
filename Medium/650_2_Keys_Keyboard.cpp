//dp
//Runtime 0
//Memory Usage 5.9

class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        for(int i = 2; i <= n; ++i){
            while(n % i == 0){
                res += i;
                n /= i;
            }
        }
        return res;
    }
};