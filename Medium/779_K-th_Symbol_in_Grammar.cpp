//sort
//Runtime 56
//Memory Usage 20

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       	vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
	   	int len = nums.size();
        if(len < 3 || nums.back() < 0 ||  nums.front() > 0) return ans;
		for(int i = 0; i < len; ++i){
            if(nums[i] > 0) break;
			int left = i + 1;
			int right = len - 1;
			while(left < right){
				int sum = nums[i] + nums[left] + nums[right];
				if(sum == 0) {
					ans.push_back({nums[i], nums[left], nums[right]});
					while(right > left && nums[left] == nums[left + 1]) ++left;
					while(right > left && nums[right] == nums[right - 1]) --right;
					++left, --right;
				}else if(sum > 0)--right;
				else ++left;
			}
            while(i < len - 1 && nums[i] == nums[i + 1]) ++i;

		}	



		return ans;	
    }
};
