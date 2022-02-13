//Monotinic Stack
//Runtime 144
//Memory Usage 85.1

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        stack<int> stk;
        int n = temps.size();
        vector<int> res(n);
        for(int i = n - 1; i >= 0; --i){
            while(!stk.empty() && temps[stk.top()] <= temps[i])
                stk.pop();
            res[i] = stk.empty() ? 0 : stk.top() - i;
            stk.push(i);
        }
        return res;
    }
};