//Greedy
//Runtime 103
//Memory Usage 70.4

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;

        int n = nums.size(), mi = -1, mn = -1, l = -1;

        for(int i = 0; i < n; ++i) {
            int cur = nums[i];

            if(cur < minK || cur > maxK) {
                mi = mn = -1, l = i;
            } else {
                if(minK == cur)
                    mi = i;
                if(maxK == cur)
                    mn = i;
                if(mi != -1 && mn != -1)
                    res += min(mi, mn) - l;
            }
        }

        return res;
    }
};