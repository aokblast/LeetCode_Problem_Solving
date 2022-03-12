//
//Runtime 0
//Memory Usage 6.1

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        bool mp[56] = {0};
        for(const char c : jewels)
            mp[islower(c) ? c - 'a' : c + 26 - 'A'] = true;
        int res = 0;
        for(const char c : stones)
            res += mp[islower(c) ? c - 'a' : c + 26 - 'A'];
        return res;
    }
};