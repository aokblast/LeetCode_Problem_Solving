//
//Runtime 114
//Memory Usage 106.5

static auto _______ = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();

        
        for(int l = 0; l < n; ++l) {
            if(nums[l] == 0) {
                int r = l;
                while(r < n && nums[r] == 0)
                    ++r;
                    
                long long cnt = r - l;
                l = r;

                res += (1 + cnt) * cnt / 2;
            }
        }

        return res;


    }
};