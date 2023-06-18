//Greedy
//Runtime 166
//Memory Usage 59.9

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        for(const auto a : arr)
            mp[a]++;

        map<int, int> cnts;

        for (const auto [_, val] : mp)
            cnts[val]++;

        int res = 0;
        
        for(const auto [val, cnt] : cnts)
            if((val * cnt) <= k)
                k -= val * cnt;
            else  {
                int cur = k / val;
                k = 0;
                res += cnt - cur;
            }
                
            

        return res;
    }
};