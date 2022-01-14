//
//Runtime 0
//Memory Usage 6.1
class Solution {
public:
    string solveEquation(string equation) {
        auto iter = equation.begin();
        int x = 0, y = 0, num = 0;
        bool neg = false, isx = false, hasNum = false;
        while(iter != equation.end() && *iter != '='){
            if(*iter == 'x'){
                if(!hasNum && num == 0)num = 1;
                isx = true;
            }else if(*iter == '+' || *iter == '-'){
                if(isx)x += neg ? -1 * num : num;
                else y += neg ? -1 * num : num;
                num = 0, neg = (*iter == '-'), isx = false;
                hasNum = false;
            }else{
                num = num * 10 - '0' + *iter;
                hasNum = true;
            }
            ++iter;
        }
        if(isx)x += neg ? -1 * num : num;
        else y += neg ? -1 * num : num;
        num = 0, neg = false, isx = false, hasNum = false;
        
        if(*iter == '='){
            ++iter;
            while(iter != equation.end()){
                if(*iter == 'x'){
                    if(!hasNum && num == 0)num = 1;
                    isx = true;
                }else if(*iter == '+' || *iter == '-'){
                    if(isx)x += neg ? num : -1 * num;
                    else y += neg ? num : -1 * num;
                    num = 0, neg = (*iter == '-'), isx = false;
                    hasNum = false;
                }else{
                    num = num * 10 - '0' + *iter;
                    hasNum = true;
                }
                ++iter;
            }
        }else{
            return "No solution";
        }
        if(isx)x += neg ?  num : -1 * num;
        else y += neg ? num : -1 * num;
        num = 0, neg = false, isx = false, hasNum = false;
        
        if(x == 0 && y == 0){
            return "Infinite solutions";
        }else{
            return x == 0 ? "No solution" : "x=" + to_string(-1 * y / x);
        }
    }
};