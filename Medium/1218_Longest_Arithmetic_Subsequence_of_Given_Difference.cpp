//dp
//Runtime 103
//Memory Usage 49.3

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int mp[10005 * 4] = {0}, res = 1;
        
        for(const int num : arr) 
            res = max(mp[num + 20010] = mp[num + 20010 - difference] + 1, res);
        
        return res;
    }
};