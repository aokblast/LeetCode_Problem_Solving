//
//Runtime 138
//Memory Usage 108

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ji = 0, ou = 1, sum = 0, res = 0, n = arr.size();
        constexpr static int MOD = 1e9 + 7;
        for(const int num: arr) {
            sum += num;
            res = (res + (sum % 2 ? (ji++, ou) : (ou++, ji))) % MOD;
        }

        return res;
    }
};