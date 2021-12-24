//Andrew
//Runtime: 36
//Memory Usage: 19.8


pair<int, int> operator-(const pair<int, int> &p1, const pair<int, int> &p2){
    return {p1.first - p2.first, p1.second - p2.second};
}

int operator*(const pair<int, int> &p1, const pair<int ,int> &p2){
    return (p1.first * p2.second - p2.first * p1.second);
}

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& t) {
        int n = t.size();
        vector<pair<int, int>> trees(n);
        vector<bool> used(n);
        for(int i = 0; i < n; ++i){
            trees[i]  = {t[i][0], t[i][1]};
        }
        sort(trees.begin(), trees.end());
        vector<int> stk(n + 5);
        int to = 0;
        
        for(int i = 0; i < n; ++i){
            while(to >= 2 && (trees[stk[to]] - trees[stk[to - 1]] ) * (trees[i] - trees[stk[to]]) < 0)used[stk[to--]] = false;
            stk[++to] = i;
            used[i] = true;
        }
        used[0] = false;

        
        for(int i = n - 1; i >= 0; --i){
            if(used[i]) continue;
            while(to >= 2 && (trees[stk[to]] - trees[stk[to - 1]] ) * (trees[i] - trees[stk[to]]) < 0)used[stk[to--]] = false;
            stk[++to] = i;
            used[i] = true;
        }
        
        
        vector<vector<int>> res(to - 1);
        for(int i = 1; i < to; ++i){
            res[i - 1] = {trees[stk[i]].first, trees[stk[i]].second};
        }
        return res;
    }
};