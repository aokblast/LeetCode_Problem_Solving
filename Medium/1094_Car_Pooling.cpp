//Prefix Sum
//Runtime 52
//Memory Usage 48.1

class Solution {
public:
    int cnt[1005] = {0};
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int ma = 0;
        for(const auto &trip : trips){
            cnt[trip[1]] += trip[0];
            cnt[trip[2]] -= trip[0];
            ma = max(ma, trip[2]);
        }
        int cur = 0;
        for(int i = 0; i <= ma; ++i){
            cur += cnt[i];
            if(cur > capacity)return false;
        }
        return true;
    }
};