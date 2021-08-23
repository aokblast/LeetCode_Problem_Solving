//Monotonic Stack
//Runtime 104
//Memory Usage 61.5
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        
        stack<int> stk;
        heights.push_back(0);
        int size = heights.size();
        for(int i = 0; i < size; ++i){
            if(stk.empty() || heights[stk.top()] < heights[i]) stk.push(i);
            else{
                int n = stk.top(); stk.pop();
                result = max(result, heights[n]  * (stk.empty() ? i : (i - stk.top() - 1)));
                --i;
            }
        }
        return result;
    }
};
