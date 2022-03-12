//
//Runtime: 67
//Memory Usage: 52.2

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size(), res = 0, wd = 0, red = 0;
        for(int i = 0; i < n; ++i){
            int num = nums[i];
            if(right >= num && left <= num){
                wd += red + 1;
                red = 0;
                res += wd;

            }else if(left > num){
                res += wd;
                ++red;
            }else{
                wd = 0;
                red = 0;
            }
        }
        return res;

    }
};