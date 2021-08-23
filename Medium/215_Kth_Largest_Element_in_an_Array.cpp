// Sort + Linear traversal
//Runtime 8
//Memory Usage 10

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        auto last = nums.rend();
        auto iter = nums.rbegin();
        int prev = -200000;
        for(; iter != last; ++iter, --k){
            if(k == 1) break;
        }
        
        return *iter;
    }
};


//QuickSelect
//Runtime 4
//Memory Usage 10
class Solution {
public:
    int helper(vector<int> &nums, int left, int right){
    if(left >= right) return left;
    swap(nums[(left) + rand() % (right - left)], nums[right]);
    int index = left, pivotVal = nums[right];
	for(int i = left; i <= right - 1; ++i) if(nums[i] < pivotVal) swap(nums[i], nums[index++]);
	swap(nums[right], nums[index]);
	return index;
	
    }
    int quickSelect(vector<int> &nums, int left, int right, int k){
    int index = helper(nums, left, right);
	if(k == index) return nums[index];
	else if(k < index) return quickSelect(nums, left, index - 1, k);
	else return quickSelect(nums, index + 1, right, k);

    }
 	
   int findKthLargest(vector<int>& nums, int k) {
       srand(time(NULL));
	return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};