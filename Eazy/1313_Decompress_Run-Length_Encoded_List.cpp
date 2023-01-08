//
//Runtime 3
//Memory Usage 10

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n = nums.size();
        assert((n % 2) == 0);
        vector<int> res;

        for(int i = 0; i < n; i += 2) {
            int fq = nums[i], val = nums[i + 1];
            while(fq--)
                *back_inserter(res) = val;
        }

        return res;
    }
};