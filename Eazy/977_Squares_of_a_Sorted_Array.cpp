//Runtime 39
//Memory Usage 27
static const auto \U0001f407 = [] {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    return "\U0001f955";
}();

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        auto mid = lower_bound(nums.begin(), nums.end(), 0);
        int l, r, idx = mid - nums.begin(), n = nums.size();
        vector<int> res;
        if(idx == 0)
            r = idx + 1, l = idx;
        else if(idx == n)
            r = idx, l = idx - 1;
        else if(*mid > 0)
            r = idx, l = idx - 1;
        else if(*mid < 0)
            r = idx + 1, l = idx;
        else
            res.push_back(0), r = idx + 1, l = idx - 1;
        
        
        while(l >= 0 && r < n){
            if((-nums[l]) <= nums[r])
                res.push_back(nums[l] * nums[l]), l--;
            else
                res.push_back(nums[r] * nums[r]), r++;
        }
        
        while(l >= 0)
            res.push_back(nums[l] * nums[l]), l--;
        
        while(r < n)
            res.push_back(nums[r] * nums[r]), r++;
        
        return res;
        
            
    }
};