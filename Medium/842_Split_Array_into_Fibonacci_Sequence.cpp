//dfs
//Runtime 0
//Memory Usage 6.4

class Solution {
public:
    vector<int> res;
    int n;
    bool dfs(const string &num, int idx){
        if(idx == n)
            return res.size() >= 3;
        if(res.size() >= 2 && (long)res[res.size() - 1] + res[res.size() - 2] > INT_MAX) 
            return false;
        if(num[idx] == '0'){
            if(res.size() < 2 || res[res.size() - 1] + res[res.size() - 2] == 0){
                res.push_back(0);
                if(dfs(num, idx + 1))
                    return true;
                res.pop_back();
                
            }
            return false;
        }
            
        long val = 0;
        for(int i = idx; i < n; ++i){
            val = val * 10 - '0' + num[i];
            if(val >= INT_MAX)
                return false;
            if(res.size() < 2 || res[res.size() - 1] + res[res.size() - 2] == val){
                res.push_back(val);
                if(dfs(num, i + 1))
                    return true;
                res.pop_back();
            }
        
        }
        return false;
    }
    
    vector<int> splitIntoFibonacci(string num) {
        n = num.size();
        dfs(num, 0);
        return res;
    }
};