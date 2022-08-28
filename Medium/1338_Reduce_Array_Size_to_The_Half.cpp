//
//Runtime 195
//Memory Usage 78.2

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        
        for(const int num : arr)
            ++mp[num];
        
        int cnt = 0;
        
        vector<int> v;
        
        for(const auto [a, cnt] : mp)
            v.push_back(cnt);
        
        sort(v.begin(), v.end(), greater());
        
        int cur = arr.size();
        int lim = cur / 2, i = 0, res = 0;
        
        while(cur > lim)
            cur -= v[i++], ++res;
        
        return res;
    }
};