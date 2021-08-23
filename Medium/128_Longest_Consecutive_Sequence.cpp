//sort
//Runtime 36 
//Memory Usage 22.4
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int ans = 0;
        int cnt = 1;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 1; i < size; ++i){
            if(nums[i] == nums[i - 1]) continue;
            if(nums[i]  == nums[i - 1] + 1){
                ++cnt;
            }else{
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};

//unordered_map
//Runtime 68
//Memory Usage 31
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> count;
        int res = 0;
        for(auto &n : nums){
            if(count.find(n) != count.end()) continue;
            int left = count.find(n - 1) == count.end() ? 0 : count[n - 1];
            int right = count.find(n + 1) == count.end() ? 0 : count[n + 1];
            int sum = left + right  + 1;
            count[n - left] = count[n + right] = count[n] = sum;
            res = max(res, sum);
        }
        return res;
    }
};
