//
//Runtime 136
//Memory Usage 59.8

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<pair<int, int>> v(n);
        vector<int> res(n);
        for(int i = 0; i < n; ++i)
            v[i] = {nums2[i], i};
        sort(v.begin(), v.end());
        sort(nums1.begin(), nums1.end());
        int l = 0, r = n - 1;
        for(int i = n - 1; i >= 0; --i)
            res[v[i].second] =  v[i].first < nums1[r] ? nums1[r--] : nums1[l++];
        
        return res;
    }
};