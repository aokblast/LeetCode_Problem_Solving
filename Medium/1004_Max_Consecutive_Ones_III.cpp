//Greedy
//Runtime 79
//Memory Usgae 55.4

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0, low = 0, cnt = 0, n = nums.size();
        
        for(int r = 0; r < n; ++r){
            cnt += nums[r] == 0;
            if(cnt > k){
                while(nums[low] == 1)
                    ++low;
                ++low;
                --cnt;
            }
            res = max(res, r - low + 1);
        }

        return res;
        
        
    }
};