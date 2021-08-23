//DFS
//Runtime 8
//Memory Usage 10.1
class Solution {
public:
    vector<vector<int>> result;
    int end, num;
    void dfs(vector<int> &cur, int size, int start){
        if(size == num){
            result.push_back(cur);
            return;
        }else if((end - start + 1) < (num - size)){
            return;
        }
        for(int i = start; i <= end; ++i){
            cur.push_back(i);
            dfs(cur, size + 1, i  + 1);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        end = n, num = k;
        vector<int> tmp;
        dfs(tmp, 0, 1);
        return result;
    }
};
