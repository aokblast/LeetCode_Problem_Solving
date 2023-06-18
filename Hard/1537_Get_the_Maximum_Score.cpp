//Greedy
//Runtime 108
//Memory 55.6
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, n = nums1.size(), m = nums2.size();
        long res = 0;
        long s1 = 0, s2 = 0;
        constexpr int MOD = 1e9 + 7;
        
        while(i < n && j < m) {
            int n1 = nums1[i], n2 = nums2[j];
            if(n1 < n2)
                s1 += nums1[i++];
            else if(n1 > n2)
                s2 += nums2[j++];
            else
                res += n1 + max(s1, s2), i++, j++, s1 = s2 = 0;
        }

        while(i < n)
            s1 += nums1[i++];
        while(j < m)
            s2 += nums2[j++];

        res += max(s1, s2);
        res = (res + MOD) % MOD;

        return res;
    }
};