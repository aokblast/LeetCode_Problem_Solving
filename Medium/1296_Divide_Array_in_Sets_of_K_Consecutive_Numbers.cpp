//Greedy
//Runtime 219
//Memory Usage 51.2

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> mp;
        
        for(const int h : nums)
            mp[h]++;
        while(mp.size()){
            bool res = false;
            auto [val, sz] = *mp.begin();
            for(int i = 0; i < k; ++i){
                if(mp.find(val + i) == mp.end() || mp[val + i] < sz)
                    return false;
                mp[val + i] -= sz;
                if(mp[val + i] == 0)
                    mp.erase(val + i);
            }
            
        }
        return true;
    }
};
