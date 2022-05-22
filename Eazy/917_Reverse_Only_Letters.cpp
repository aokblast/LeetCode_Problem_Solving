//
//Runtime 0
//Memory Usage 6.1

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size(), l = 0, r = n - 1;
        while(l < r){
            while(l < r && !isalpha(s[l]))
                ++l;
            while(l < r && !isalpha(s[r]))
                --r;
            if(l == r)
                break;
            swap(s[l], s[r]);
            ++l, --r;
        }
        return s;
    }
};