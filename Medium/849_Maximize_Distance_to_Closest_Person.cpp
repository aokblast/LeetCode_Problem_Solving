//
//Runtime 12
//Memory Usage 17
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int l = 0, r = 0, n = seats.size(), res = 0;
        while(r < n){
            while(r < n && seats[r] == 0)++r;
            if(l == 0 && seats[l] == 0){
                res = max(res, r);
            }else if(r == n){
                res = max(res, r - l - 1);
            }else{
                res = max(res, (r - l) / 2);
            }
            l = r;
            ++r;
        }
        return res;
    }
};