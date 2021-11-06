//Runtime 1
//Memory Usage 38.9
//Given the root of a binary tree, return the leftmost value in the last row of
//the tree.
//
//
// Example 1:
//
//
//Input: root = [2,1,3]
//Output: 1
//
//
// Example 2:
//
//
//Input: root = [1,2,3,4,null,5,6,null,null,7]
//Output: 7
//
//
//
// Constraints:
//
//
// The number of nodes in the tree is in the range [1, 10⁴].
// -2³¹ <= Node.val <= 2³¹ - 1
//
// Related Topics Tree Depth-First Search Breadth-First Search Binary Tree 👍 17
//22 👎 196


//leetcode submit region begin(Prohibit modification and deletion)


import java.util.Queue;

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
    public int findBottomLeftValue(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        TreeNode tmp;
        int last = -1;
        while(!q.isEmpty()){
            int sz = q.size();
            tmp = q.poll();
            last = tmp.val;
            --sz;
            if(tmp.left != null) q.offer(tmp.left);
            if(tmp.right != null)q.offer(tmp.right);
            while((sz--) > 0){
                tmp = q.poll();
                if(tmp.left != null) q.offer(tmp.left);
                if(tmp.right != null)q.offer(tmp.right);
            }
        }
        return last;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
