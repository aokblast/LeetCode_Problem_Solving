//
//Runtime 63
//Memory Usage 19.7

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int l[26], r[26];
        memset(l, 0x3f, sizeof(l));
        memset(r, -1, sizeof(r));

        auto maxSubstr = [&](int i) { 
            int right = r[s[i] - 'a'];
            for(auto j = i; j <= right; ++j) {
                if(l[s[j] - 'a'] < i) {
                    return -1;
                }
                right = max(right, r[s[j] - 'a']);
            }

            return right;
        };

        int n = s.size();

        for(int i = 0; i < n; ++i) {
            const int idx = s[i] - 'a';
            l[idx] = min(l[idx], i);
            r[idx] = i;
        }

        vector<string> res;
        int right = -1;

        for(int i = 0; i < n; ++i) {
            if(i == l[s[i] - 'a']) {
                auto nr = maxSubstr(i);
                if(nr != -1) {
                    if(i > right) 
                        res.push_back("");
                    right = nr;
                    res.back() = s.substr(i, right - i + 1);
                }
            }
        }

        return res;
    }
};