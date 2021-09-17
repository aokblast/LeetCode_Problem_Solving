//
//Runtime 0
//Memory Usage 6.8
class Solution {
public:
    int cnt[26] = {0};
    
    int characterReplacement(string s, int k) {
        int ans = 0, l = 0, ml = 0, n = s.size();
        for(int r = 0; r < n; ++r){
            ml = max(ml, ++cnt[s[r] - 'A']);
            while(r - l + 1 - ml > k){
                --cnt[s[l] - 'A'];
                ++l;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
