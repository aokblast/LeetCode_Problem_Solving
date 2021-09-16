//Binary Search
//Runtime 3
//Memory Usage 7.3
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long left = 0, right = 0;
        for(int &n : nums) left = max(left, (long)n), right += n;
        while(left < right){
            long mid = left + ((right - left) >> 1);
            if(!cs(nums, m, mid))left = mid + 1;
            else right = mid;
        }
        return left;
    }
    
    bool cs(vector<int> &nums, int m, int val){
        int cnt = 0, acc = 0;
        for(int &n : nums){
            acc += n;
            if(acc > val){
                acc = n;
                ++cnt;
                if(cnt >= m) return false;
            }
        }
        return true;
    }
};
