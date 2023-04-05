//
//Runtime 12
//Memory Usage 13.1

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2,   int d) {
        int res = 0;


        sort(arr2.begin(), arr2.end());

        for(const auto num : arr1) {
            auto u = lower_bound(arr2.begin(), arr2.end(), num - d);
            auto l = upper_bound(arr2.begin(), arr2.end(), num + d);

            res += u == l;
        }

        return res;
        
    }
};