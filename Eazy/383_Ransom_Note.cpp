//
//Runtime 7 
//Memory Usage 8.7
class Solution {
public:
    int cnt[26];
    bool canConstruct(string ransomNote, string magazine) {
        for(char &c : magazine){
            ++cnt[c - 'a'];
        }
        for(char &c : ransomNote){
            if(!(cnt[c - 'a']--))return false;
        }
        return true;
    }
};
