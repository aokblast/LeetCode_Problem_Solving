//dp
//Runtime 111
//Memory Usage 43.2

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int res = 0, n = nums.size();
        
        unordered_map<int, int> cnts;
        int  mp[n + 1], mx = 0;

        memset(mp, 0, sizeof(mp));
        
        for(int i = 0; i < n; ++i) {
            int num = nums[i];
            int cur = cnts[num];
            mx = max(mx, ++cnts[num]);
            
            if(mp[cur] > 0)
                --mp[cur];
            
            ++mp[cur + 1];
            
            if(mx * mp[mx] == i || (mx - 1) * (mp[mx - 1] + 1)  == i || mx == 1)
                res = i + 1;
            
        }
        
        return res;
    }
};