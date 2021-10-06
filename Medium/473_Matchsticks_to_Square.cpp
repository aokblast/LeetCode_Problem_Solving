//dfs
//Runtime 12
//Memory Usage  13
class Solution {
public:
    int side;
    bool makesquare(vector<int>& matchsticks) {
        side = accumulate(matchsticks.begin(), matchsticks.end(), 0) ;
        if(side % 4)return false;
        side /= 4;
        unordered_set<int> vis;
        return dfs(matchsticks, 0, vis, side);
    }
    bool dfs(vector<int> &ms, int pos , unordered_set<int> &vis, int accu, int cnt = 4, int comb = 0){
        if(accu < 0 || vis.find(comb) != vis.end())return false;
        
        if(!cnt)return true;
        if(!accu)return dfs(ms, 0, vis, side, cnt - 1, comb | (1 << (30 - cnt)));
        for(int i = pos; i < ms.size(); ++i){
            if(comb  & (1 << i))continue;
            if(dfs(ms, i + 1, vis, accu - ms[i], cnt, comb | (1 << i)))return true;
        }
        vis.insert(comb);
        return false;
    }
};
