//
//Runtime 4
//Memory 8.1

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for(const auto acc : accounts){
            int cur = 0;
            for(const int a : acc)
                cur += a;
            res = max(res, cur);
        }
        return res;
    }
};