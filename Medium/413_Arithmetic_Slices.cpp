//Rolling Windows
//Runtime 0
//Memory Usage 7.4
class Solution {
public:
    int cha[5005] = {0};
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 1; ++i){
            cha[i] = nums[i + 1] - nums[i];
        }
        int l = 0, r = 0;
        int ans = 0;
        while(r < n - 1){
            while(r < n - 2 && cha[r] == cha[r + 1]) ++r;
            ++r;
            int u = r - l;
            ans += (u * (u - 1) / 2);
            l = r;
        }
        return ans;
    }
};
