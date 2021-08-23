//stack
//Runtime 0
//Memory Usage 8.1

class Solution {
public:
    string reverseWords(string s) {
        vector<string> Ss;
        string tmp;
        int left = 0, size = s.size();
        while(left < size){
            if(s[left] == ' ') {
                ++left;
                continue;
            }
            tmp.clear();
            while(s[left] != ' ' && left < size){
                
                tmp += s[left++];
            }
            Ss.push_back(tmp);
        }
        size = Ss.size();
        string result;
        while(size--){
            result += Ss[size] + ' ';
        }
        if(!result.empty()) result.pop_back();
        return result;
        
    }
};
