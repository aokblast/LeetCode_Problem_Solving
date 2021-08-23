//bfs
//Runtime 0
//Memory Usage 12.2
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<int> tmp;
            int mode = 1;
            stack<TreeNode*> stk;
            stack<TreeNode*> next;
            if(root)stk.push(root);
            while(!stk.empty()){
                int size = stk.size();
                tmp.clear();
                while(size--){
                    TreeNode *top = stk.top(); stk.pop();
                    tmp.push_back(top->val);
                    if(mode == 1){
                    if(top->left) next.push(top->left);
                    if(top->right) next.push(top->right);
                    }else{
                        if(top->right) next.push(top->right);
                        if(top->left) next.push(top->left);
                        
                    }
                }
                result.push_back(tmp);
                stk.swap(next);
                mode ^= 1;
            }
        return result;
     }
};
