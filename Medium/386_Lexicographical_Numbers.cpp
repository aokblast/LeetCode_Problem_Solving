//dfs
//Runtime 3 
//Memory Usage 12.1
class Solution {
public:
    vector<int> ans;
    void dfs(int num, int &n){
        if(num > n) return;
        for(int i = 0; i <= 9; ++i){
            if(n < num * 10 + i) break;
            ans.push_back(num * 10 + i);
            dfs(num * 10 + i, n);
        }
    }
    vector<int> lexicalOrder(int n) {
        
        for(int i = 1; i <= 9; ++i){
            if(n < i) break;
            ans.push_back(i);
            dfs(i, n);
        }
        return ans;
    }
};
