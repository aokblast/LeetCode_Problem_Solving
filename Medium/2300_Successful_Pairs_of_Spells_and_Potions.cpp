//
//Runtime 216
//Memory Usage 99.9

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        vector<int> res;

        for(const auto s : spells) 
            res.emplace_back(s * (long long)potions.front() >= success 
            ? potions.size() : (long long)s * potions.back() < success ? 0 
            : (potions.end() - lower_bound(potions.begin(), potions.end(), (success + s - 1) / s)));
        
        return res;
    }
};
