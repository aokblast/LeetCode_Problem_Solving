//stable_sort
//Runtime 23
//Memory Usage  18.5

class Solution {
public:
    string arrangeWords(string text) {
        string cur;
        vector<string> v;

        text[0] = tolower(text[0]);
        stringstream ss(text);

        while(ss >> cur) {
            v.push_back(cur);
        }

        stable_sort(v.begin(), v.end(), [](const auto &s1, const auto &s2) {return s1.size() < s2.size();});

        text.clear();

        for(const auto &s : v) 
            text += s + ' ';

        text[0] = toupper(text[0]);
        
        text.pop_back();
        return text;
    }
};