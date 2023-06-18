//
//Runtime 0
//Memory Usage 6.4

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;

        int n = word1.size(), m = word2.size(), i = 0, j = 0;

        while(i < n && j < m) {
            res += word1[i++];
            res += word2[j++];
        }

        while(i < n)
            res += word1[i++];
        
        while(j < m)
            res += word2[j++];
        
        return res;
    }
};