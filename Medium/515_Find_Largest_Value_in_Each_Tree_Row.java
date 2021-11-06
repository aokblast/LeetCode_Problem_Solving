//BFS
//Runtime 1
//Memory Usage 39.1

import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;
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
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        Queue<TreeNode> q  = new LinkedList<>();
        if(root != null) q.offer(root);
        while(!q.isEmpty()){
            int val  = Integer.MIN_VALUE;
            int sz = q.size();
            while((sz--) > 0){
                TreeNode front = q.poll();
                val = Math.max(val, front.val);
                if(front.left != null)q.offer(front.left);
                if(front.right != null)q.offer(front.right);
            }
            res.add(val);

        }
        return res;
        
    }
}
