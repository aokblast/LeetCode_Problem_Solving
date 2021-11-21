//DFS
//Runtime 6
//Memory Usage 39.6

class Solution {
    public int findPairs(int[] nums, int k) {
        Arrays.sort(nums);
        Set<Integer> s = new HashSet<Integer>();
        int ans = 0;
        for(int i = 0; i < nums.length; ++i){
            if(s.contains(nums[i] - k)){
                ++ans;
            }
            s.add(nums[i]);
            while((k != 0 && i < nums.length - 1 && nums[i] == nums[i + 1]) || (k == 0 && i < nums.length - 2 && nums[i] == nums[i + 2])) ++i;
        }
        return ans;
    }
}