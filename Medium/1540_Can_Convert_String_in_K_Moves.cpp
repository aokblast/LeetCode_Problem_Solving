//Greedy
//Runtime 51
//Memory Usage 17.6

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int cnt[26] = {0}, n = s.size();

        if(s.size() != t.size())
            return false;

        for(int i = 0; i < n; ++i) {
            int diff = t[i] - s[i];
            if(diff < 0)
                diff += 26;
            cnt[diff]++;
        }

        for(int i = 1; i < 26; ++i) {
            if((cnt[i] - 1) * 26 + i > k)
                return false;
        }

        return true;
    }
};