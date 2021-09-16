//
//Runtime 0
//Memory Usage 6.5
class Solution {
public:
    int m[60] = {0};
    int longestPalindrome(string s) {
        for(char &c : s)++m[c >= 'a' ? (c - 'a' + 28) : (c - 'A')];
        int ans = 0;
        bool hasOne = false;
        
        for(int &p : m){
            ans += p - (p & 1);
            ans += (!hasOne && p & 1 ? (hasOne = true) : 0);
        }
        return ans;
    }
};
