//
//Runtime 0
//Memory Usage 6.2

class Solution {
public:
    string fractionAddition(string expression) {
        stack<pair<int, int>> stk;
        char last = 0;
        int n1 = 0, n2 = 0, mode = 1, neg1 = false, neg2 = false;
        for(const char c : expression){
            if(n1 == 0 && c == '-'){
                neg1 = true;
                
            }else if(n2 == 0 && c == '-'){
                neg2 = true;
            }
            else if(isdigit(c)){
                if(mode == 1){
                    n1 = n1 * 10 + c - '0';  
                }else {
                    n2 = n2 * 10 + c - '0';
                }
            }else if(c == '/'){
                mode *= -1;
            }else if(mode == -1){
                n1 *= neg1 ? -1 : 1;
                n2 *= neg2 ? -1 : 1;
                
                stk.push({n1, n2});
                mode = 1, n1 = n2 = neg1 = neg2 = 0;
                if(last == '+'){
                    pair<int, int> f1 = stk.top(); stk.pop();
                    pair<int, int> f2 = stk.top(); stk.pop();
                    pair<int, int> res = {f2.first * f1.second + f1.first * f2.second, f1.second * f2.second};
                    
                    if(res.first == 0) {res.second = 1; stk.push(res);last = c; continue;}
                    int g = gcd(res.first, res.second);
                    res.first /= g, res.second /= g;
                    stk.push(res);
                }else if(last == '-'){
                    pair<int, int> f1 = stk.top(); stk.pop();
                    pair<int, int> f2 = stk.top(); stk.pop();
                    pair<int, int> res = {f2.first * f1.second - f1.first * f2.second, f1.second * f2.second};
                    if(res.first == 0) {res.second = 1; stk.push(res);last = c; continue;}
                    int g = gcd(res.first, res.second);
                    res.first /= g, res.second /= g;
                    stk.push(res);
                }
                last = c;

            }
        }
        n1 *= neg1 ? -1 : 1;
        n2 *= neg2 ? -1 : 1;
        stk.push({n1, n2});
        
                        if(last == '+'){

                    pair<int, int> f1 = stk.top(); stk.pop();
                    pair<int, int> f2 = stk.top(); stk.pop();
                    pair<int, int> res = {f2.first * f1.second + f1.first * f2.second, f1.second * f2.second};
                            
                    int g = gcd(res.first, res.second);
                            
                    if(res.first == 0) {res.second = 1; return to_string(res.first) + "/" + to_string(res.second);}
                    res.first /= g, res.second /= g;
                    stk.push(res);
                }else if(last == '-'){
                    pair<int, int> f1 = stk.top(); stk.pop();
                    pair<int, int> f2 = stk.top(); stk.pop();
                    pair<int, int> res = {f2.first * f1.second - f1.first * f2.second, f1.second * f2.second};
                    int g = gcd(res.first, res.second);
                    if(res.first == 0) {res.second = 1; return to_string(res.first) + "/" + to_string(res.second);}
                    res.first /= g, res.second /= g;
                    stk.push(res);
                }
        return to_string(stk.top().first * (stk.top().second < 0 ? -1 : 1)) + "/" + to_string(abs(stk.top().second));
        
    }
    int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);}
};