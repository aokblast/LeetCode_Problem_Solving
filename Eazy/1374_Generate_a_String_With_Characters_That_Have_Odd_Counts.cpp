//
//Runtime 0
//Memory Usage 6.4

class Solution {
public:
    string generateTheString(int n) {
        return string(n - (n % 2 == 0), 'a') + string(n % 2 == 0, 'b');
    }
};