//Binary Search
//Runtime 68 
//Memory Usage 43
class Solution {
public:
    int preSum[10000 + 5] = {0}, sum = 0, n;
    Solution(vector<int>& w) {
        n = w.size();
        for(int i = 0; i < n; ++i){
            preSum[i] = w[i] + (i == 0 ? 0 : preSum[i - 1]);
        }
        sum = preSum[n - 1];
    }
    
    int pickIndex() {
        int num = rand() % sum + 1;
        return lower_bound(preSum, preSum + n, num) - preSum;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
