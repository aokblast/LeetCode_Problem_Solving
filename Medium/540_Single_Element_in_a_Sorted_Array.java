//Binary Search
//Runtime 0
//Memory Usage 42.5

class Solution {
    public int singleNonDuplicate(int[] nums) {
        if(nums.length == 1)return nums[0];
        if(nums[0] != nums[1])return nums[0];
        if(nums[nums.length - 1] != nums[nums.length - 2])return nums[nums.length - 1];
        int left = 1, right = nums.length - 2;
        int mid;
        while(true){
            mid = left + ((right - left) >> 1);
            if(nums[mid] == nums[mid - 1] || nums[mid] == nums[mid + 1]){
                if(nums[mid] == nums[mid - 1]){
                    if((mid + 1) % 2 == 1 ){
                        right = mid - 2;
                    }else{
                        left = mid + 1;
                    }
                }else{
                    if(mid % 2 == 1){
                        right = mid - 1;
                    }else{
                        left = mid + 2;
                    }
                }
            }else{
                return nums[mid];
            }

        }
    }
}
