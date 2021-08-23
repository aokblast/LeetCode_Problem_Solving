//
//Runtime 4 
//Memory Usage 7.3
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            while(left < right && (!isalpha(s[right]) && !isdigit(s[right]))) --right;
            while(left < right && !isalpha(s[left]) && !isdigit(s[left])) ++left;
            if(isalpha(s[right]) && tolower(s[right]) != tolower(s[left])) return false;
            else if(isdigit(s[right]) && s[right] != s[left]) return false;
            --right, ++left;
        }
        return true;
    }
};
