//
//Runtime 67
//Memory Usage 24.5

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        vector<int> mx(4, INT_MIN), mi(4, INT_MAX);
        int n = arr1.size();
        
        for(int i = 0; i < n; ++i) {
            mx[0] = max(mx[0], i + arr1[i] + arr2[i]);
            mi[0] = min(mi[0], i + arr1[i] + arr2[i]);
            mx[1] = max(mx[1], i - arr1[i] + arr2[i]);
            mi[1] = min(mi[1], i - arr1[i] + arr2[i]);
            mx[2] = max(mx[2], i + arr1[i] - arr2[i]);
            mi[2] = min(mi[2], i + arr1[i] - arr2[i]);
            mx[3] = max(mx[3], i - arr1[i] - arr2[i]);
            mi[3] = min(mi[3], i - arr1[i] - arr2[i]);

        }
        
        return max({mx[0] - mi[0], mx[1] - mi[1], mx[2] - mi[2], mx[3] - mi[3]});
    }
};