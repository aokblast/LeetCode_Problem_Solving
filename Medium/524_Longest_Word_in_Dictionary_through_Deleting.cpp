//
//Runtime 48
//Memory Usage 14.8
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](string &s1, string &s2){
                                 return s1.size() == s2.size() ? s1 < s2 : s1.size() > s2.size();
        });
        for(const string &str : d){
            int i = 0, j = 0;
            for(; i < s.size() && j < str.size(); j += s[i] == str[j], ++i);
            if(j == str.size())return str;
        }
        return "";
    }
};
