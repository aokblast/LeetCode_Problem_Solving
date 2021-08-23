//Monotonic Stack
//Runtime 24
//Memory Usage 12.1
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)  return 0;
        vector<int> heights(matrix[0].size());
        int result = 0;
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                heights[j] = matrix[i][j] == '0' ? 0 : heights[j] + 1;
            }
            result = max(result, largestRectangleArea(heights));
        }
        return result;
    }
};
