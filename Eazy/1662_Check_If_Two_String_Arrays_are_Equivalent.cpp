//
//Runtime 7
//Memory Usage 11.6
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a, b;
        
        for(const auto &word : word1)
            a += word;
        
        for(const auto &word : word2)
            b += word;
        
        return a == b;
    }
};