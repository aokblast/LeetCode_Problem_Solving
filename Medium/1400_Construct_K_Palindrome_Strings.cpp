//
//Runtime 26
//Memory Usage 11.9

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.size())
            return false;

        char cnts[26] = {0};
        
        for(const auto c : s)
            cnts[c - 'a']++;

        int res = 0;
        
        for(const int cur : cnts) 
            res += cur % 2;

        return res <= k;
    }
};