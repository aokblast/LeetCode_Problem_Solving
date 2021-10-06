//
//Runtime 4 
//Memory Usage 7.3
class Solution {
public:
    int cnt[26] = {0};
    int findSubstringInWraproundString(string p) {
        int len = 1, n = p.size();
        for(int i = 0; i < n; ++i){
            
            if(i > 0 && ((p[i - 1] + 1  == p[i]) || (p[i - 1] == 'z' && p[i] == 'a'))){
                ++len;
            }else{
                len = 1;
            }
            
            cnt[p[i] - 'a'] = max(cnt[p[i] - 'a'], len);
        }
        return accumulate(cnt, cnt + 26, 0);
    }
};
