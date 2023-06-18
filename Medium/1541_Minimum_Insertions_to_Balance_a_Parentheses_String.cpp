//Greedy
//Runtime 30
//Memory Usage 14.1

class Solution {
public:
    int minInsertions(string s) {
        int res = 0, l = 0, n = s.size();
        s.push_back('_');

        for(int i = 0; i < n; ++i) {
            const char c = s[i];
            switch(c) {
                case '(':
                    ++l;
                    break;
                case ')':
                    if(l) {
                        if(s[i + 1] != ')')
                            res += 1;
                        else
                            ++i;
                        --l;
                    } else {
                        if(s[i + 1] == ')')
                            res += 1, ++i;
                        else
                            res += 2;
                    }
                    break;
            }
        }

        return res + l * 2;
    }
};