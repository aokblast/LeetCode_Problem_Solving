//Rolling Windows
//Runtime 103
//Memory Usage 6.2
class Solution {
public:
    
    
    int longestSubstring(string s, int k) {
        int n = s.size();
        int l = 0;
        int ans = 0 ;
        while((l + k) <= n){
            int m[26] = {0}, r = l, mask = 0;
            for(int j = l; j < n; ++j){
                int t = s[j] - 'a';
                ++m[t];
                if(m[t] < k) mask |= (1 << t);
                else mask &= (~(1 << t));
                if(!mask){
                    ans = max(ans, j - l + 1);
                    r = j;
                }
            }
            l = r + 1;
            
        }
        return ans;
    }
};
