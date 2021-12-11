//
//Runtime 32 
//Memory Usage 28.4
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); i += 2){
            ans += nums[i];
        }
        return ans;
    }
};
