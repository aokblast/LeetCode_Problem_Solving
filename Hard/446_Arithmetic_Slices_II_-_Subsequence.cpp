//LIS
//Runtime 596
//Memory Usage 153.9
class Solution {
public:
    unordered_map<long, int> ma[1005];
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = 0;  i < n ;++i){
            for(int j = 0; j < i; ++j){
                long delta = (long)(nums[i]) - nums[j];
                ++ma[i][delta];
                if(ma[j].find(delta) != ma[j].end()){
                    ans += ma[j][delta];
                    ma[i][delta] += ma[j][delta];
                } 
            }
        }
        return ans;
    }
};
