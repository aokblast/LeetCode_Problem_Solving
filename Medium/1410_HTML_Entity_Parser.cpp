//
//Runtime 47
//Memory Usage 18.9

class Solution {
public:
    string entityParser(string text) {
        int n = text.size();
        string res;
        for(int i = 0; i < n; ++i) {
            if(text[i] == '&' && i < (n - 1)) {
                if(text[i + 1] == 'q' && text.substr(i + 2, 4) == "uot;") {
                    res.push_back('"'), i += 5;
                } else if(text[i + 1] == 'a' && text.substr(i + 2, 4) == "pos;") {
                    res.push_back('\''), i += 5;
                } else if(text[i + 1] == 'a' && text.substr(i + 2, 3) == "mp;") {
                    res.push_back('&'), i += 4;
                } else if(text[i + 1] == 'g' && text.substr(i + 2, 2) == "t;") {
                    res.push_back('>'), i += 3;
                } else if(text[i + 1] == 'l' && text.substr(i + 2, 2) == "t;") {
                    res.push_back('<'), i += 3;
                } else if(text[i + 1] == 'f' && text.substr(i + 2, 5) == "rasl;") {
                    res.push_back('/'), i += 6;
                } else
                    res.push_back('&');
            } else {
                res.push_back(text[i]);
            }
        }

        return res;
    }
};