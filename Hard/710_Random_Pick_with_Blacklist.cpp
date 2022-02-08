//
//Runtime 120
//Memory 71.6
class Solution {
public:
    Solution(int n, vector<int>& blacklist) {
        m = n - blacklist.size();
        unordered_set<int> s;
        for(int num = m; num < n; ++num)
            s.insert(num);
        for(const int num : blacklist)
            s.erase(num);
        auto it = s.begin();
        for (const int num : blacklist) {
            if (num < m) mp[num] = *it++;
        }
    }
    
    int pick() {
        int k = rand() % m;
        return mp.find(k) != mp.end() ? mp[k] : k;
    }
    
    unordered_map<int, int> mp;
    int m;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */