//
//Runtime 0
//Memory Usage 6.2
class Solution {
public:
    string toLowerCase(string s) {
        for_each(s.begin(), s.end(), [](auto &c){c = tolower(c);});
        return s;
    }
};