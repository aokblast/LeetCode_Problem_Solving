//sort
//Runtime 8 
//Memory Usage 10.2
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        
        vector<string> ans(n);
        vector<pair<int, int>> p;
        for(int i = 0; i < n; ++i){
            p.push_back({score[i], i});
        }
        
        sort(p.begin(), p.end(), greater<>());
        ans[p[0].second] = "Gold Medal";
        if(n == 1)return ans;
        ans[p[1].second] = "Silver Medal";
        if(n == 2)return ans;
        ans[p[2].second] = "Bronze Medal";
        if(n == 3)return ans;
        for(int i = 3; i < n; ++i){
            ans[p[i].second] = to_string(i + 1);
        }
        return ans;
    }
};
