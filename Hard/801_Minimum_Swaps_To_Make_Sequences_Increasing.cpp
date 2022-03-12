//dp
//Runtime 168
//Memory Usage 90.1
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), s = 1, ns = 0;
        for(int i = 1; i < n; ++i){
            int cs = INT_MAX, cns = INT_MAX;
            if(nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]){
                cns = min(cns, ns);
                cs = min(cs, s + 1);
            }
            if(nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]){
                cns = min(cns, s);
                cs = min(cs, ns + 1);
            }
            s = cs;
            ns = cns; 
        }
        return min(s, ns);
    }
};