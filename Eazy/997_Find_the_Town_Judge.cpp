//
//Runtime 144
//Memory Usage 60.8


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1)return 1;
        vector<int> cnt1(n + 1), cnt2(n + 1);
        for(const auto &t : trust){
            ++cnt1[t[1]];
            ++cnt2[t[0]];
            
        }
        int res = -1;
        
        for(int i = 1; i <= n; ++i){
            if(cnt1[i] == n - 1 && cnt2[i] == 0)res = i;
        }
        
        return res;
        
    }
};