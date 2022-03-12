//
//Runtime 8
//Memory Usage  12.3
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), res = 1;
        vector<int> mn(n);
        mn[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; --i)
            mn[i] = min(arr[i], mn[i + 1]);
        int mx = 0;
        for(int i = 0; i < n - 1; ++i)
            mx = max(mx, arr[i]), res += mx <= mn[i + 1];
        return res;
    }
};