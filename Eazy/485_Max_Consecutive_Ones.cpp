//
//Runtime 25 
//Memory Usage 36.2
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(nums[i] == 1){
                int tmp = 1;
                ++i;
                while( i < n && nums[i]  == 1 )++tmp, ++i;
                --i;
                
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};
