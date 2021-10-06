//
//Runtime 68
//Memory Usage 28.1
class Solution {
public:
    int *m;
    int tot;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        tot = maxChoosableInteger;
        m = (int *)calloc(1048576, sizeof(int));
        return dfs(desiredTotal, 0);
    }
    bool dfs(int rem, int used){
        if(m[used]){
            return m[used] == 1;
        }
        
        for(int i = 0; i < tot; ++i){
            int cur = 1 << i;
            if((used & cur))continue;
            if((i + 1) >= rem || !dfs(rem - i - 1, used | cur)){
                m[used] = 1;
                return true;
            }
        }
        m[used] = -1;
        return false;
    }
};
