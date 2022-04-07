//dp
//Runtime 35
//Memory Usage 14.1

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        
        int cnt[n];
        memset(cnt, 0, sizeof(cnt));
        string res(n, '.');
        int cur = 0;
        for(int i = 0; i < n; ++i){
            char c = dominoes[i];
            if(c == '.')
                cur = max(cur - 1, 0);
            else if(c == 'L')
                cur = 0;
            else
                cur = n;
            cnt[i] = cur;
        }
        cur = 0;
        for(int i = n - 1; i >= 0; --i){
            char c = dominoes[i];
            if(c == '.')
                cur = max(cur - 1, 0);
            else if(c == 'R')
                cur = 0;
            else
                cur = n;
            if(cur > cnt[i])
                res[i] = 'L';
            if(cur < cnt[i])
                res[i] = 'R';
        }

        return res;
    }
};