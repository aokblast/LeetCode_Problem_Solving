//
//Runtime 25
//Memory Usage 23.1

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> a, b;
        for(const int num : nums)
            if(num % 2)
                a.push_back(num);
            else
                b.push_back(num);
        int n = nums.size();
        for(int i = 0; i < n; ++i)
            if(i % 2)
                nums[i] = a[i / 2];
            else
                nums[i] = b[i / 2];
        return nums;
    }
};