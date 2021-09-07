//
//Runtime 0 
//Memory Usage 7.6
class Solution {
public:
bool isvow(char c)
    {
        c=tolower(c);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r){
            while(!isvow(s[l]) && l < r) ++l;
            while(!isvow(s[r]) && l < r) --r;
            if(l < r) swap(s[l], s[r]);
            ++l, -- r;
        }
        return s;
    }
};
