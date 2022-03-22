//
//Runtime 0
//Memory Usage 6.1

class Solution {
public:
    string maskPII(string s) {
        if(s.find('@') != string::npos){
            //mail
            auto pos = s.find('@');
            string res = s[0] + string("*****") + s[pos - 1] + s.substr(pos);
            for_each(res.begin(), res.end(), [](char &c){c = tolower(c);});
            return res;
        }
        
        vector<string> vs = {"", "+*-", "+**-", "+***-"};
        
        int cnt = 0;
        for_each(s.begin(), s.end(), [&](char c){cnt += isdigit(c);});
        int tu = 4;
        string tmp;
        for(int i = s.size() - 1; i >= 0; --i){
            char c = s[i];
            if(!isdigit(c))
                continue;
            tmp += c;
            if(!--tu)
                break;
            
        }
        reverse(tmp.begin(), tmp.end());
        
        return vs[cnt - 10] + "***-***-" + tmp;
        
        
    }
};