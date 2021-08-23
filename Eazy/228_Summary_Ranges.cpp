//
//Runtime 0
//Memory Usgae 6.9
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int i = 0, n = nums.size(), left = 0, right = 0;
        while(i < n){
            left = nums[i];
            while(i < n - 1 && nums[i] + 1 == nums[i + 1] ){
                ++i;
            }
            right = nums[i++];

            if(left == right)result.push_back(to_string(left));
            else {
                result.push_back(to_string(left) + "->" + to_string(right));
            }
        }
                                 
        return result;
    }
};
