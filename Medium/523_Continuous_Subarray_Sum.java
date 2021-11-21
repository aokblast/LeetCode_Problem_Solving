//
//Runtime 13
//Memory Usage 48.4

class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        Set<Integer> s = new HashSet<>();
        int pre = 0, sum = 0;
        for(int i = 0; i < nums.length; ++i){
            sum = (sum  + nums[i]) % k;
            if(s.contains(sum)){
                return true;
            }
            s.add(pre);
            pre = sum;
        }
        return false;
    }

}
