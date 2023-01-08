//sliding window
//Runtime 163
//Memory Usage 67.5

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), res = 0, cnt = 0, odd = 0;
        
        for(int i = 0, j = 0; i < n; ++i) {
            if(nums[i] & 1) {
                ++odd;
                if(odd >= k) {
                    cnt = 1;
                    while(!(nums[j++] & 1))
                        ++cnt;
                    res += cnt;
                }
            } else if(odd >= k) {
                res += cnt;
            }
        }
        
        return res;
        
    }
};