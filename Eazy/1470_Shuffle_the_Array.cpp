//
//Runtime 3
//Memory Usage 9.7

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int a = 0, b = n, i = 0;
        vector<int> res(n * 2);

        while(b < n * 2)
            if(i % 2 ==0)
                res[i++] = nums[a++];
            else
                res[i++] = nums[b++];
        
        return res;
    }
};