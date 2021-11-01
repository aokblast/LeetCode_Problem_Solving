//Greedy
//Runtime 252 
//Memory Usage 84.4
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> stk;
        for(int i = 0; i < n; ++i){
            while(!stk.empty() && nums[stk.top()] < nums[i]){
                ans[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        for(int i = 0; i < n; ++i){
            while(!stk.empty() && nums[stk.top()] < nums[i]){
                ans[stk.top()] = nums[i];
                stk.pop();
            }
        }
        
        
        return ans;
        
    }
};
