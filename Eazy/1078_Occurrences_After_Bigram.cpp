//
//Runtime 2
//Memory Usage 6.6
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        stringstream ss(text);
        string fir, sec, s;
        
        while(ss >> s) {
            if(fir == first && sec == second)
                res.push_back(s);
            
            fir = sec;
            sec = s;
        }
        
        return res;
    }
};