//dfs
//Runtime 1
//Memory Usage 42.3

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
	int[] pre, post;
    int p;
	private TreeNode dfs(int l, int r) {
		if(l > r)
			return null;
		TreeNode res = new TreeNode();
		res.val = post[p];
		--p;

		if(l == r)
			return res;
		int mid = l;
		while(mid <= r) {
			if(pre[mid] == post[p])
				break;
			else
				++mid;
		}
		
		res.right = dfs(mid, r);
		res.left = dfs(l + 1, mid - 1);
		return res;
		
	}
    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
    	pre = preorder;
    	post = postorder;
    	p = pre.length - 1;
    	return dfs(0, pre.length - 1);
    }
}