//Greedy
//Runtime 8
//Memory Usage 9.4

class Solution {
public:
    int minFlips(string target) {
        int res = 0;
        for(const char c : target) {
            res += (c - '0') != (res % 2);
        }

        return res;
    }
};