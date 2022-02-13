//
//Runtime 0
//Memory Usage 7.7

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        bool in = false;
        string line;
        for(const string &s : source){
            
            for(int i = 0; i < s.size(); ++i){
                if(!in && s[i] == '/' && i < s.size() - 1 && (s[i + 1] == '/' || s[i + 1] == '*')){
                    if(s[i + 1] == '/')
                        break;
                    else if(s[i + 1] == '*')
                        in = true;
                    ++i;
                }else if(in && s[i] == '*' && i < s.size() - 1 && s[i + 1] == '/'){
                    ++i, in = false;
                
                }else{
                    if(!in)
                        line += s[i];
                }
            }
            
            if(!in && !line.empty())
                res.push_back(line), line.clear();
        }
        return res;
    }
};