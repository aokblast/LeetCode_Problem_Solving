//
//Runtime 4
//Memory Usage 11.3
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
       long long miss = 1, ans = 0, i = 0;
        while(miss <= n){
            if(i < nums.size() && nums[i] <= miss){
                miss += nums[i++];
            }else{
                miss += miss;
                ++ans;
            }
        }
        return ans;
    }
};
