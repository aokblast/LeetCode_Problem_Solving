//Monotonic Stack
//Runtime 90
//Memory Usage 39.5

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int res = 0;
        const int MOD = 1e9 + 7;
        int last[30005] = {0};
        stack<int> stk;
        int n = arr.size();
        for(int i = 0; i < n; ++i){
            while(!stk.empty() && arr[stk.top()] >= arr[i])
                stk.pop();
            int cur = 0;
            if(stk.size()){
                cur = ((i - stk.top()) * arr[i]) % MOD;
                cur += last[stk.top()];
            }else{
                cur = ((i + 1) * arr[i]) % MOD;
            }
            last[i] = cur;
            res = (res + cur) % MOD;
            stk.push(i);
        }
        return res;
        

    }
};