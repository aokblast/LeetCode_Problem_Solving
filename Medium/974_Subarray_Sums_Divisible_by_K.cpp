//
//Runtime 78
//Memory Usage 31.6

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int cur = 0, res = 0;
        
        unordered_map<int, int> mp;
        
        for(const int num : nums){
            cur = ((cur + num % k) + k) % k;
            res += cur == 0;
            
            if(mp.find(cur) != mp.end())
                res += mp[cur];
            
            ++mp[cur];
            
        }
        return res;
        
        
    }
};