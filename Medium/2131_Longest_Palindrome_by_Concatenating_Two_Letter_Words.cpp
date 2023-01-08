//
//Runtime 532
//Memory Usage 167.2

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int mp[17567] = {0};
        
        
        int res = 0;
        int hasMid = 0;
        
        for (const auto &word : words) {
            int cur = (word[0] - 'a') * 26 + word[1] - 'a';
            int rev = (word[1] - 'a') * 26 + word[0] - 'a';
            bool same = rev == cur;
            
            if (mp[rev]) {
                --mp[rev];
                res += 4;
                if(same)
                    hasMid--;
            } else {
                ++mp[cur];
                if(same)
                    hasMid++;
            }
            
        }
        
        return res + (hasMid > 0 ? 2 : 0);
    }
};