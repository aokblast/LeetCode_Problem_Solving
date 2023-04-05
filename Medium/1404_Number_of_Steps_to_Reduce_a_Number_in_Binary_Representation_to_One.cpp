//
//Runtime 0
//Memory Usage 6.4

class Solution {
public:
    int numSteps(string s) {

        int res = 0;
        
        while(s.size() && s != "1") {
            char t = s.back();

            if(t == '1') {
                for(int i = s.size() - 1; i >= 0; --i) {
                    if(s[i] == '0') {
                        s[i] = '1';
                        break;
                    } else {
                        s[i] = '0';
                    }
                }

                ++res;
            } else {
                ++res;
                s.pop_back();
            }

        }

        return res;
    }
};