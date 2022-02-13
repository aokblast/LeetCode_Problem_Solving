//Binary Search
//Runtime 12
//Memory Usage 10.2

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int t) {
        sort(nums.begin(), nums.end());
        int l = 0, n = nums.size(), r = nums.back() - nums.front();
        while(l < r){
            int mid = (l + r) >> 1;
            int cnt = 0, k = 0;
            for(int i = 0; i < n; ++i){
                while(k < n && nums[i] - nums[k] > mid)
                    ++k;
                cnt += i - k;
            }
            if(cnt >= t){
                r = mid;
            }else{
                l = mid + 1;
            }
            
            
        }
        return r;
    }
};