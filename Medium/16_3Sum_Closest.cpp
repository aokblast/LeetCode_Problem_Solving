//sort
//Runtime 4
//Memory Usage 9.8

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       	sort(nums.begin(), nums.end());
	   	int len = nums.size();
 		int diff = INT_MAX, ans = abs(nums[0] + nums[1] + nums[2] - target);
		for(int i = 0; i < len; ++i){
			if((len - i ) > 3 && target < nums[i] * 3) return min(ans, nums[i] + nums[i + 1] + nums[i + 2]);
            if (i>0 and nums[i] == nums[i-1]) continue;
			int left = i + 1;
			int right = len - 1;
			while(left < right){
				int sum = nums[i] + nums[left] + nums[right];
				int nDiff = abs(sum - target);
				if(diff > nDiff) ans = sum, diff = nDiff;
				if(sum > target) --right;
				else if(sum < target) ++left;
                else return sum;
			}
		}
		return ans;		
    }
};
