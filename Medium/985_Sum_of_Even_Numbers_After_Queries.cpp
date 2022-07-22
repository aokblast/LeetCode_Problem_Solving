//
//Runtime 121
//Memory Usgae 46

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int cur = 0;
        
        for(const int num : nums)
            if(!(num % 2))
                cur += num;
        vector<int> res;
        for(const auto &q : queries){
            int tmp = nums[q[1]];
            if(!(abs(tmp) % 2))
                cur -= tmp;
            tmp += q[0];
            nums[q[1]] = tmp;
            if(!(abs(tmp) % 2))
                cur += tmp;
            res.push_back(cur);
        }
        return res;
    }
};