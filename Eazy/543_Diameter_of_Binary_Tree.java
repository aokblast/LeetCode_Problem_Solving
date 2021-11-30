//DFS
//Runtime 0
//Memory Usage 40.3

class Solution {
    private int max;
    int dfs(TreeNode root){
        if(root == null)return 0;
        int left = dfs(root.left);
        int right = dfs(root.right);
        max = Math.max(left + right, max);
        return Math.max(left, right) + 1;

    }

    public int diameterOfBinaryTree(TreeNode root) {
        dfs(root);
        return max;
    }
}