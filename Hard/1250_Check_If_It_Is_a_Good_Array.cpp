//gcd
//Runtime 44
//Memory Usage 29.3

class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    bool isGoodArray(vector<int>& nums) {
        int M = 0;
        for(auto &c : nums){
            M = Solution::gcd(M, c);
        }
        return M == 1;
    }
};
