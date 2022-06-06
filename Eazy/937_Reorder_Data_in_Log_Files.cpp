//
//Runtime 12
//Memory Usage 11.1
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        stable_sort(logs.begin(), logs.end(), [](const string &s1, const string &s2){
            if(isdigit(s1.back()))
                return false;
            if(isdigit(s2.back()))
                return true;
            auto pos1 = s1.find(' '), pos2 = s2.find(' ');
            string a = s1.substr(pos1), b = s2.substr(pos2);
            return a == b ? s1 < s2 : a < b;
            
        });
        
        return logs;
    }
};