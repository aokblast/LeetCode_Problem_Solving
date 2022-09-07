//Robin Karps
//Runtime 1620
//Memory Usage 350.4
class Solution {
public:
    string longestDupSubstring(string s) {
        string res;
        int n = s.size();
        
        const int MOD = 1e7 + 7;
        
        int power[n + 1];
        memset(power, 0, sizeof(power));
        
        power[0] = 1;
        
        for(int i = 1; i <= n; ++i)
            power[i] = power[i - 1] * 26 % MOD;
        
        int l = 0, r = n;
        
        auto rk = [&](int len) -> string {
            if(len == 0)
                return "";
            static unordered_map<int, vector<int>> hashes;
            
            hashes.clear();
            
            int cur = 0;
            
            for(int i = 0; i < len; ++i)
                cur = (cur * 26 + s[i] - 'a') % MOD;
            
            
            hashes[cur].push_back(len - 1);
            
            for(int i = len; i < n; ++i){
                cur = (((cur - (s[i - len] - 'a') * power[len - 1] % MOD) * 26 % MOD + s[i] - 'a') % MOD + MOD) % MOD;
                if(hashes[cur].size()){
                    for(const int idx : hashes[cur]){
                        bool ans = true;
                        for(int j = 0; j < len; ++j){
                            if(s[i - j] != s[idx - j]){
                                ans = false;
                                break;
                            }
                        }
                        if(ans)
                            return s.substr(i - len + 1, len);
                    }
                }
                
                
                hashes[cur].push_back(i);
                
            }
            return "";
        };
        
        while(l < r){
            int mid = l + (r - l) / 2;
            string cur = rk(mid);
            if(cur.size() > res.size()){
                l = mid + 1;
                res = cur;
            }else{
                r = mid;
            }
        }
        return res;
    }
};