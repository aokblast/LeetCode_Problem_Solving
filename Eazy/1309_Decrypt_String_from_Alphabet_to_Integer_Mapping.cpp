//
//Runtime 0
//Memory Usage 6.3

class Solution {
public:
    string freqAlphabets(string s) {
        int n = s.size();
        string res;

        int i = n - 1;
        while(i >= 0) {
            if(s[i] == '#') {
                res += (char)('a' + (s[i - 2] - '0') * 10 + (s[i - 1] - '0') - 1);
                i -= 3;
            } else {
                res += (char)('a' - 1 + s[i] - '0');
                --i;
            }
        }

        reverse(res.begin(), res.end());

        return res;

    }
};