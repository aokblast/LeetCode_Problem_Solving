//
//Runtime 3
//Memory Usage 7.4

class Solution {
public:
    string reformat(string s) {
        string res;
        string a, b;

        for(const auto c : s)
            if(isalpha(c))
                a += c;
            else 
                b += c;

        if(b.size() > a.size())
            swap(a, b);
        
        if((int)a.size() - (int)b.size() > 1)
            return "";
        
        for(int i = 0; i < s.size(); ++i) {
            if(i & 1)
                res += b.back(), b.pop_back();
            else
                res += a.back(), a.pop_back();
        }

        return res;
    }
};