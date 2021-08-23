//stack
//Runtime 4
//Memory Usage 11.9

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        for(string &s : tokens){
            if(isdigit(s[0]) || (s[0] == '-' && s.size() >= 2)){
                num.push(stoi(s));
            }else{
                int num2 = num.top(); num.pop();
                int num1 = num.top(); num.pop();
                switch(s[0]){
                    case '+':
                        num.push(num1 + num2);
                        break;
                    case '-':
                        num.push(num1 - num2);
                        break;
                    case '*':
                        num.push(num1 * num2);
                        break;
                    case '/':
                        num.push(num1 / num2);
                        break;
                }
                
            }
        }
        return num.top();
    }
};
