//
//Runtime 44
//Memory Usage 23.7

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        
        int res = INT_MIN, mx[n];
        
        memset(mx, 0, sizeof(mx));
        
        for(int i = 0, cur = 0; i < n; ++i) 
            cur = max(cur + arr[i], arr[i]), res = max(res, cur), mx[i] = cur;
        
        for(int i = n - 1, cur = 0; i >= 2; --i)
            cur = max(cur + arr[i], arr[i]), res = max({res, cur, cur + mx[i - 2]});
        
        return res;
    }
};