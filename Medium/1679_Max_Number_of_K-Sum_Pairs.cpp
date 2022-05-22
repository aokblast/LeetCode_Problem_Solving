//greedy
//Runtime 133
//Memory Usage 58.2

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int l = 0, r = nums.size() - 1, res = 0;
        while(l < r){
            int sum = nums[l] + nums[r];
            if(sum == k)
                ++res, ++l, --r;
            else if(sum > k)
                --r;
            else
                ++l;
            
        }
        return res;
        
            
    }
};