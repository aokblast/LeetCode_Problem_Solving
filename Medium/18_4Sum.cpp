//
//Runtime 8
//Memory Usage 13

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
 		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		int len = nums.size();
        if(len < 4) return ans;
 		for(int i = 0; i < len - 3; ++i){
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[len-3]+nums[len-2]+nums[len-1]<target) continue;
			for(int j = i + 1; j < len; ++j){
				int left = j + 1;
				int right = len - 1;
				while(left < right){
					int sum = nums[i] + nums[j] + nums[left] + nums[right];
					if(sum == target){
						ans.push_back({nums[i], nums[j], nums[left], nums[right]});
						while(left < right && nums[left] == nums[left + 1]) ++left;
						while(left < right && nums[right] == nums[right - 1]) --right;
						++left, --right;
					}else if(sum < target) ++left;
					else --right;
				}
				while(j < len - 1&& nums[j] == nums[j + 1]) ++j;

			}
			while(i < len - 1 && nums[i] == nums[i + 1]) ++i;
		}
		return ans;		
    }
};
