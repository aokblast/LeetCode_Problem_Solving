//Runtime 7
//Memory Usage 45.94
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        for(const auto num : nums) {
            if(num == 0)
                return 0;
            neg += num < 0;
        }
        return neg % 2 == 1 ? -1 : 1;
    }
};