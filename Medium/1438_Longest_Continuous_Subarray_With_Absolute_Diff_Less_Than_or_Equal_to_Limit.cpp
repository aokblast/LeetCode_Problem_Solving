//Greedy
//Rumtime 119
//Memory Usage 52.2


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxq, minq;

        int res = 0, n = nums.size(), l = 0;

        for(int r = 0; r < n; ++r) {
            while(maxq.size() && maxq.back() < nums[r])
                maxq.pop_back();
            while(minq.size() && minq.back() > nums[r])
                minq.pop_back();
            
            maxq.push_back(nums[r]);
            minq.push_back(nums[r]);

            while(maxq.front() - minq.front() > limit) {
                if(maxq.front() == nums[l])
                    maxq.pop_front();

                if(minq.front() == nums[l])
                    minq.pop_front();
                ++l;
            }

            res = max(res, r - l + 1);
        }

        return res;

    }
};