//dp
//Runtime 4
//Memory Usage 13.3

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
	int subvalue = -200000000;
	int result = -200000000;

	for(int i : nums){
	   subvalue = max(subvalue + i, i);
	   result = max(result, subvalue);
	} 
	return result;
    }

};

//DAC
//Runtime 4
//Memory Usage 13

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       return recursive(nums, 0, nums.size() - 1);
    }
    int recursive(vector<int> &nums, int left, int right){
    	if(left >= right) return nums[left];
	int mid = (left + right) / 2;
	int leftMax = recursive(nums, left, mid - 1);
	int rightMax = recursive(nums, mid + 1, right);
	int leftTmp = 0, tmp = 0, rightTmp = 0;
	for(int i = mid - 1; i >= left; --i){
	    tmp = tmp + nums[i];
	    leftTmp = max(leftTmp, tmp);    
	}
	tmp = 0;
	for(int i = mid+ 1; i <=right; ++i){
		tmp = tmp + nums[i];
		rightTmp = max(rightTmp, tmp);
	}
	int midMax = leftTmp + rightTmp + nums[mid];
	return max(max(midMax, rightMax), leftMax);



   		 
    }
};
