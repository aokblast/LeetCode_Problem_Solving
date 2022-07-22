//Rolling Window
//Runtime 127
//Memory Usage 39
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        
        int l = 0, r = 0, n = nums.size(), cur = 0, prev = 0;
        int res = 0;
        while(r < n){
            cur += (++cnt[nums[r]]) == 1;
            ++r;
            int tmp = 0;
            if(cur == k){
                if(l != 0 && nums[l - 1] != nums[r - 1])
                    prev = 0;
                while(l <= r){
                    ++tmp;
                    if(k != (cur -= ((--cnt[nums[l++]]) == 0)))
                        break;
                
                }
            }
            prev += tmp;
            res += prev;
        }
        return res;
    }
};
