//Binary Search
//Runtime 37
//Memory Usage 22.3


class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = *max_element(nums.begin(), nums.end()) + 1;

        while(l < r) {
            int mid = l + (r - l) / 2, sum = 0;

            for(const int num : nums)
                sum += num / mid + !!(num % mid);

            
            if(sum <= threshold) 
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};