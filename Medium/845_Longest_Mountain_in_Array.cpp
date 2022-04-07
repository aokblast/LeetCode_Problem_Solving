//
//Runtime 19
//Memory Usage 18.5

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int len[n];
        memset(len, 0, sizeof(len));
        len[0] = 1;
        for(int i = 1; i < n; ++i)
            len[i] = arr[i] > arr[i - 1] ? len[i - 1] + 1 : 1;
        int res = 0, cnt = 1;
        for(int i = n - 2; i >= 0; --i){
            cnt = arr[i] > arr[i + 1] ? cnt + 1 : 1;
            if(cnt > 1 && len[i] > 1)
                res = max(res, cnt + len[i]  - 1);
        }
        return res;
    }
};