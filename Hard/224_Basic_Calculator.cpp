//Polish Reverse
//Runtime 16
//Memory Usage 9.1 
class Solution {
public:
    inline int getOper(int a, int b, char oper){
        switch(oper){
            case '+': return a + b; break;
            case '-': return a - b; break;
            case '*': return a * b; break;
            case '/': return a / b; break;   
        }
        return 0;
    }
    int calculate(string s) {
        int size= s.size(), num = 0, num1, num2;
        stack<int> stk;
        stk.push(0);
        stack<char> operStk;
        for(int i = 0; i < size; ++i){
            char c = s[i];
            if(isdigit(c)){
                num = 0;
                for(; i < size && isdigit(s[i]); ++i){
                    num = num * 10  - '0' + s[i];
                    
                }
                --i;
                stk.push(num);
            }else{
                switch(c){
                    case '+':
                    case '-':
                        while(!operStk.empty() && (operStk.top() != '(')){
                            num1 = stk.top(); stk.pop();
                            num2 = stk.top(); stk.pop();
                            stk.push(getOper(num2, num1, operStk.top()));
                            operStk.pop();
                        }
                        operStk.push(c);
                        break;
                    case '*':
                    case '/':
                        while(!operStk.empty() && (operStk.top() == '*' || operStk.top() == '/')){
                            num1 = stk.top(); stk.pop();
                            num2 = stk.top(); stk.pop();
                            stk.push(getOper(num1, num2, operStk.top()));
                            operStk.pop();
                        }
                        operStk.push(c);
                        break;
                    case '(':
                        operStk.push(c);
                        break;
                    case ')':
                        while(operStk.top() != '('){
                            num1 = stk.top(); stk.pop();
                            num2 = stk.top(); stk.pop();
                            stk.push(getOper(num2, num1, operStk.top()));
                            operStk.pop();
                        }
                        operStk.pop();
                        break;
                }
            }

        }
                    while(!operStk.empty()){
                                num1 = stk.top(); stk.pop();
                            num2 = stk.top(); stk.pop();
                            stk.push(getOper(num2, num1, operStk.top()));
                            operStk.pop();
            }
            return stk.top();
    }
};
