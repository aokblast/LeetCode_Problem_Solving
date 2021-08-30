//dfs
//Runtime 0
//Memory Usage 6.2
class Solution {
public:
    bool dfs(string &num, int start, vector<long> &ans){
        if(start == num.size()){
            return ans.size() >= 3;
        }
        for(int len = 1; len + start <= num.size() && len <= 19; ++len){
            string str = num.substr(start, len);
            if(str[0] == '0' && str.size() >= 2) break;
            long n = stol(str), s = ans.size();
            if(s >= 2 && ans[s - 1] + ans[s - 2] != n) continue;
            ans.push_back(n);
            if(dfs(num, start + len, ans)) return true;
            ans.pop_back();
        
        }
        return false;
        
        
    }
    
    
    bool isAdditiveNumber(string num) {
        vector<long> n;
        return dfs(num, 0, n);
    }
    
    
};

