//
//Runtime 1
//Memory Usage 37.1

class Solution {
    public boolean detectCapitalUse(String word) {
        int lit = 0, big = 0;
        int sz = word.length();
        for(int i = 0; i < sz; ++i){
            Character c = word.charAt(i);
            if(c <= 'Z' && c >= 'A')++big;
            else if(c <= 'z' && c >= 'a')++lit;
        }

        return sz == lit || sz == big || (word.charAt(0) <= 'Z' && word.charAt(0) >= 'A' && lit == sz - 1);
    }
}
