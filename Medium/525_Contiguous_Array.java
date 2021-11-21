//
//Runtime 35
//Memory Usage 99.1

class Solution {
    public int findMaxLength(int[] nums) {
        Map<Integer, Integer> m = new HashMap<>();
        int cnt = 0, ans = 0;
        m.put(0, 0);
        for(int i = 0 ;  i < nums.length; ++i){
            cnt += nums[i] == 1 ? 1 : -1;
            if(m.containsKey(cnt)){
                ans = Math.max(ans, i + 1 - m.get(cnt));
            }else{
                m.put(cnt, i + 1);
            }
        }
        return ans;
    }
}