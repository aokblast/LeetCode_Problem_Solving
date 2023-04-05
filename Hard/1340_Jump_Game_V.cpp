//dp
//Runtime 40
//Memory Usage 19.7

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        stack<int> stk;
        vector<int> adjs[n];

        for(int i = 0; i < n; ++i) {
            while(!stk.empty() && arr[stk.top()] < arr[i]) {
                if(abs(i - stk.top()) <= d)
                    adjs[i].push_back(stk.top());
                stk.pop();
            }
            stk.push(i);
        }

        while(!stk.empty())
            stk.pop();

        for(int i = n - 1; i >= 0; --i) {
            while(!stk.empty() && arr[stk.top()] < arr[i]) {
                if(abs(i - stk.top()) <= d)
                    adjs[i].push_back(stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        vector<int> dp(n, 0);

        function<int(int)> dfs = [&](int u) {
            dp[u] = 1;
            for(const auto v : adjs[u]) {
                if(dp[v])
                    dp[u] = max(dp[u], 1 + dp[v]);
                else
                    dp[u] = max(dp[u], 1 + dfs(v));
            }
            return dp[u];
        };

        int res = 1;

        for(int i = 0; i < n; ++i) {
            if(!dp[i])
                res = max(res, dfs(i));
        }

        return res;
    }
};