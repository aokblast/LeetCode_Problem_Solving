//
//Runtime 12
//Memory Usage 8.9
class Solution {
public:
    int cnt[26];
    int tot[26];
    string originalDigits(string s) {
        for(char &c : s) ++cnt[c - 'a'];
        
        string ans;
        while(cnt['z' - 'a'])++tot[0], --cnt['z' - 'a'], --cnt['e' - 'a'], --cnt['r' - 'a'], --cnt['o' - 'a'];
        while(cnt['w' - 'a'])++tot[2], --cnt['t' - 'a'], --cnt['w' - 'a'], --cnt['o' - 'a'];
        while(cnt['u' - 'a'])++tot[4], --cnt['f' - 'a'], --cnt['o' - 'a'], --cnt['u' - 'a'], --cnt['r' - 'a'];
        while(cnt['x' - 'a'])++tot[6], --cnt['s' - 'a'], --cnt['i' - 'a'], --cnt['x' - 'a'];
        while(cnt['g' - 'a'])++tot[8], --cnt['e' - 'a'], --cnt['i' - 'a'], --cnt['g' - 'a'], --cnt['h' - 'a'], --cnt['t' - 'a'];
        while(cnt['o' - 'a'])++tot[1], --cnt['o' - 'a'], --cnt['n' - 'a'], --cnt['e' - 'a'];
        while(cnt['h' - 'a'])++tot[3], --cnt['t' - 'a'], --cnt['h' - 'a'], --cnt['r' - 'a'], cnt['e' - 'a'] -= 2;
        while(cnt['f' - 'a'])++tot[5], --cnt['f' - 'a'], --cnt['i' - 'a'], --cnt['v' - 'a'], --cnt['e' - 'a'];
        
        while(cnt['s' - 'a'])++tot[7], --cnt['s' - 'a'], cnt['e' - 'a']-=2, --cnt['v' - 'a'], --cnt['n' - 'a'];
        
        while(cnt['i' - 'a'])++tot[9], --cnt['e' - 'a'], --cnt['i' - 'a'], --cnt['g' - 'a'], --cnt['h' - 'a'], --cnt['t' - 'a'];
        for(int i = 0; i < 10; ++i){
            int t = tot[i];
            while(t--){
                ans += '0' + i;
            }
        }
        return ans;
        
    
    }
};
