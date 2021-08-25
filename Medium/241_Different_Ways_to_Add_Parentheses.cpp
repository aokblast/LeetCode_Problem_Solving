//dfs
//Runtime 0 
//Memory Usage 11
class Solution {
public:
    int getOper(int val1, int val2, char oper){
        switch(oper){
            case '+':
                return val1 + val2;
            case '-':
                return val1 - val2;
            case '*':
                return val1 * val2;
        }
        return 0;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        int size = expression.size();
        for(int i = 0; i < size; ++i){
            char e = expression[i];
            if(e == '+' || e == '-' || e == '*'){
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                for(int i = 0; i < left.size(); ++i){
                    for(int j = 0; j < right.size(); ++j){
                        ans.push_back(getOper(left[i], right[j], e));
                    }
                }
            }
        }
        if(ans.empty()) ans.push_back(stoi(expression));
        return ans;
    }
};
