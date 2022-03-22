//Runtime 3
//Memory Usage 6.5


class Solution {
public:
    string toGoatLatin(string sentence) {
        auto isVowel = [](char c){
            c = tolower(c);
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        stringstream ss(sentence);
        string res, tmp, c;
        int cnt = 0;
        while(ss >> tmp){
            if(!isVowel(tmp[0]))
                tmp = tmp.substr(1) + tmp[0];
            c += 'a';
            res += tmp  + "ma" + c + " ";
            
        }
        res.pop_back();
        return res;
    }
};