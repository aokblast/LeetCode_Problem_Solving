//
//Runtime 12 
//Memory Usage 13.9 
class Solution {
public:
    string reverseWords(string s) {
        string res;
        stringstream ss(s);
        string tmp;
        while(ss >> tmp){
            reverse(tmp.begin(), tmp.end());
            res += tmp + " ";
        }
        res.pop_back();
        return res;
    }
};
