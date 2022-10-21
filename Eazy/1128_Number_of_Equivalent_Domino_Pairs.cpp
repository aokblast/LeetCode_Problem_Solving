//
//Runtime 45
//Memory 22.1

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int mp[100] = {0};
        
        for(auto &domino : dominoes) {
            if(domino[0] > domino[1])
                swap(domino[0], domino[1]);
            mp[domino[1] * 10 + domino[0]]++;
        }
        
        int res = 0;
        
        for(const auto cnt : mp)
            res += cnt * (cnt - 1) / 2;
        
        return res;
        
    }
};