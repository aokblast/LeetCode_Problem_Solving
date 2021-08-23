//Binary Search
//Runtime 4
//Memory Usage 13.5

class Solution {
public:
    int binary_search_1(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        int result = 0;
        bool hasAnswer = false;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                result = mid;
                left = mid + 1;
                hasAnswer = true;
            }
        }
        return hasAnswer ? result : -1;
    }
    int binary_search_2(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        int result = 0;
        bool hasAnswer = false;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                result = mid;
                right = mid - 1;
                hasAnswer = true;
            }
        }
        return hasAnswer ? result : -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {binary_search_2(nums, target), binary_search_1(nums, target)};
    }
};
