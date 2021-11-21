//
//Runtime 0
//Memory Usage 38.6

class Solution {
    int prev = Integer.MAX_VALUE;
    public int getMinimumDifference(TreeNode root) {
        if(root == null)return Integer.MAX_VALUE;
        int res = getMinimumDifference(root.left);
        res = Math.min(Math.abs(root.val - prev), res);
        prev = root.val;
        res = Math.min(res, getMinimumDifference(root.right));
        return res;
    }
}
