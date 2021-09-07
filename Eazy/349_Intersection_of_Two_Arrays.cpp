//
//Runtime 4
//Memory Usage 10 
class Solution {
public:
    bool set[1005] = {false};
    bool app[1005] = {false};
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int &n : nums1) set[n] = true;
        for(int &n : nums2) if(set[n] && !app[n]) res.push_back(n), app[n] = true;
        return res;
    }
};
