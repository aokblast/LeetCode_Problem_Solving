//unordered_map
//Runtime 4
//Memory Usage 7.3
class Solution {
public:
    int cnt[256] = {0};
    bool isAnagram(string s, string t) {
        for(char &c : s)++cnt[c];
        for(char &c : t)--cnt[c];
        for(int &i : cnt) if(i) return false;
        return true;
    }
};
