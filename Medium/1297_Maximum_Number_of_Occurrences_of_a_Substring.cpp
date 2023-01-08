//
//Runtime 39
//Memory Usage 13.2

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int res = 0, n = s.size();
        unordered_map<string, int> occ;
        int cnts[26] = {0};
        int diff = 0;

        for(int i = 0; i < n; ++i) {
            if(cnts[s[i] - 'a']++ == 0)
                ++diff;
            if(i >= minSize) 
                if(--cnts[s[i - minSize] - 'a'] == 0)
                    --diff;
            if(i >= minSize - 1 && diff <= maxLetters)
                res = max(res, ++occ[s.substr(i - minSize + 1, minSize)]);
            
        }

        return res;
    }
};