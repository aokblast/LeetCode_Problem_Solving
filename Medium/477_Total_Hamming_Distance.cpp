//
//Runtime 32 
//Memory Usage  19
class Solution {
public:

    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0;  i < 32; ++i){
            int cnt = 0;
            for(const int &num : nums){
                cnt += !!(num & (1 << i)); 
            }
            ans += (cnt) * (n - cnt);
        }
        return ans;
    }
};
