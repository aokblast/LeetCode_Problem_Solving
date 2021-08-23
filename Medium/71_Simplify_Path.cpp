//Stack
//Runtime 4
//Memory Usage 8.9

class Solution {
public:
    string simplifyPath(string path) {
        string stk[1000];
        int stkTop = 0;
        string dir;
        for(auto &c : path){
            if(c == '/'){
                if(dir == "."){
                }else if(dir == ".."){
                    if(stkTop > 0)stkTop--;
                }else{
                    if(!dir.empty())stk[stkTop++] = dir;
                }
                dir.clear();
            }else{
                
                dir += c;
            }
        }
        if(dir == "."){
        }else if(dir == ".."){
        if(stkTop > 0)stkTop--;
        }else{
        if(!dir.empty())stk[stkTop++] = dir;
        }
        dir.clear();
        string result;
        for(int i = 0; i < stkTop; ++i){
            result += '/' + stk[i];
        }
        return result.empty() ? "/" : result;
    }
};
