//dp
//Runtime 394
//Memory Usage 14.8

class Solution {
public:
    
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), res = 0;
        unordered_map<int, int> idxs, dp;
        for(int i = 0; i < n; ++i)
            idxs[arr[i]] = i;
        
        for(int i = 2; i < n; ++i){
            for(int j = i - 1; j >= 1; --j){
                int val = arr[i] - arr[j];
                if(idxs.find(val) == idxs.end())
                    continue;
                if(val >= arr[j])
                    break;
                res = max(res, dp[i * n + j] = dp[j * n + idxs[val]] + 1);
                
            }    
        }
        return res + (res == 0 ? 0 : 2);
    }
};