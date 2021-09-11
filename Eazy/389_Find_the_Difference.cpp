//
//Runtime 0
//Memory Usage 6.7
class Solution {
public:
    
    char findTheDifference(string s, string t) {
        char ans = '\0';
        for(char &c : s){
            ans ^= c;
        }
        for(char &c : t){
            ans ^= c;
        }
        return ans;
    }
};
