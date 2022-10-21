//Greedy
//Runtime 0
//Memory Usage 6.2

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        int l = 0, r = n - 1;
        while(l < r) {
            if(palindrome[l] != 'a') {
                palindrome[l] = 'a';
                return palindrome;
            }
            
            ++l, --r;
        }
        if(n > 1) {
            palindrome[n - 1] = 'b';
            return palindrome;
        }
        return "";
    
    }
};