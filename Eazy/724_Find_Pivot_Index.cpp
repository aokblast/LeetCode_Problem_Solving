//
//Runtime 20
//Memory 31

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int all = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            int tmp = all - nums[i];
            if(tmp - sum == sum)
                return i;
            sum += nums[i];
        }
        return -1;
    }
};