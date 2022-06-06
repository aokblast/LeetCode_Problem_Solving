//greedy
//Runtime 191
//Memory Usage 65.5

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, min = -1;
        
        for(int num : nums){
            if(min >= num){
                res += min + 1 - num;
                num = min + 1;    
            }
            min = num;
        }
        
        
        return res;
    }
};