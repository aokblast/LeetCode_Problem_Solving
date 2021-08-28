//dfs
//Runtime 116
//Memory Usage 14.8

class Solution {
public:
    vector<string> ans;
    long t;
    void dfs(string &tmp,string &num, int start, long cnt, long diff){
        
        if(start == num.size()){
            if(cnt == t){
                ans.push_back(tmp);
            }
            return;
        }

        for(int len  = 1; len + start <= num.size(); ++len){
             string n = num.substr(start, len);
             if (n.size() > 1 && n[0] == '0') return;
            long nu = stol(n);
             if(!tmp.empty()){
                 
                 tmp += '+' + n;
                 dfs(tmp, num, start + len, cnt + nu, nu);
                for(int i = 0; i <= len; ++i){
                    tmp.pop_back();
                }
                tmp += '-' + n;
                 dfs(tmp, num, start + len, cnt - nu, -nu);
                for(int i = 0; i <= len; ++i){
                    tmp.pop_back();
                }
                tmp += '*' + n;
                 dfs(tmp, num, start + len, (cnt - diff) + diff * nu, diff * nu);
                for(int i = 0; i <= len; ++i){
                    tmp.pop_back();
                }

             }else{
                 
                tmp += n;
                 dfs(tmp, num, start + len, nu, nu );
                 
                for(int i = 0; i < len; ++i){
                    tmp.pop_back();
                }
             }
            
        }
            
        
    }
    
    vector<string> addOperators(string num, int target) {
        t = target;
        string tmp;
        dfs(tmp, num, 0, 0, 0);
        return ans;
    }
};
