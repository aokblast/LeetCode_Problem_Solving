//
//Runtime 0
//Memory Usage 8.1
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        bitset<1001> vis;
        int mp[2002] = {0};
        
        for(const int num : arr)
            mp[num + 1000]++;
        
        for(const auto cnt : mp)
            if(cnt)
                if(vis[cnt])
                    return false;
                else
                    vis[cnt] = true;
        
        return true;
    }
};