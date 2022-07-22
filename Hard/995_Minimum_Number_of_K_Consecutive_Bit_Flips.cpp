//Greedy
//Runtime 135
//Memory 106.3
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {

        int n = nums.size(), res = 0, cur = 0;
        
        for(int i = 0; i < n; ++i){
            if(i >= k && nums[i - k] == 2)
                cur ^= 1;
            if(cur == nums[i]){
                if(i + k > n)
                    return -1;
                nums[i] = 2;
                cur ^= 1;
                ++res;
            }
        }
        return res;

    }
};