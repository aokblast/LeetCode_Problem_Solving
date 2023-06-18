//
//Runtime 0
//Memory Usage 7.4

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int res = 0, n = arr.size();

        for(int i = 0; i < n; ++i) {
            int cur = 0;
            for(int j = i; j < n; ++j) {
                cur ^= arr[j];
                res += cur == 0 ? j - i : 0;
            }
        }

        return res;
    }
};