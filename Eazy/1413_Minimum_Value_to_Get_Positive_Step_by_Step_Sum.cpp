//Runtime 0
//Memory Usage 7.3

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int res = 0, acc = 0;
        for(const auto num : nums) {
            acc += num;

            if(acc)
                res = max(res, -acc);
        }

        return res + 1;
    }
};