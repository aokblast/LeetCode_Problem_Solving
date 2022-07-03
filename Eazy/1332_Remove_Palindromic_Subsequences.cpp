//
//Runtime 0
//Memory 6.3

class Solution {
public:
    int removePalindromeSub(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r)
            if(s[l] == s[r])
                ++l, --r;
            else
                return 2;
        return 1;
    }
};