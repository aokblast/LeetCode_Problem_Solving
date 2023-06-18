//dp
//Runtime 112
//Memory Usage 50.2

int powerOf2[100005] = {1};
constexpr int MOD = 1e9 + 7;

static const auto Initialize = []{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    for(int i = 1; i <= 100000; ++i){
        powerOf2[i] = powerOf2[i-1] << 1;
        if(powerOf2[i] >= MOD)
            powerOf2[i] -= MOD;
    }
    return nullptr;
}();

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0, l = 0, r = n - 1;

        vector<int> exp(n);
        
        while(l <= r) {
            if((nums[r] + nums[l]) > target)
                --r;
            else
                res = (res + powerOf2[r - l++]) % MOD;
        }
        return res;
    }
};