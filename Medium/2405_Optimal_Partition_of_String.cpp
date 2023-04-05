//Greedy
//Runtime 15
//Memory Usgae 10.3

class Solution {
public:
    int partitionString(string s) {
        int n = s.size(), res = 1, last[26];

        memset(last, -1, sizeof(last));

        int cur = 0;

        for(int i = 0; i < n; ++i) {
            if(last[s[i] - 'a'] >= cur)
                cur = i, ++res;

            last[s[i] - 'a'] = i;
        }

        return res;

    }
};