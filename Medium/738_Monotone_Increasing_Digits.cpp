//dfs
//Runtime 0
//Memory Usage 5.9

class Solution {
public:
    int res = 0;
    bool dfs(int n, int idx, long num){
        if(!idx ){
            if(num <= n){
                res = num;
                return true;
            }
                
            return false;
        }
        int down = num % 10;
        for(int i = 9; i >= down; --i){
            if(dfs(n, idx - 1, num * 10 + i))
                return true;
            
        }
        return false;
        
        
    }
    int monotoneIncreasingDigits(int n) {
        int cnt = 0, tmp = n;
        while(tmp)
            ++cnt, tmp /= 10;
        dfs(n, cnt, 0);
        return res;
        
    }
};