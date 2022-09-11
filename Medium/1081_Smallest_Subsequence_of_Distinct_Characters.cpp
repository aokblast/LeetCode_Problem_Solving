//Greedy
//Runtime 0
//Memory Usage 6.4

class Solution {
public:
    string smallestSubsequence(string s) {
        string res;
        
        int cnts[26] = {0};
        bool app[26] = {false};
        
        for(const char c : s) 
            ++cnts[c - 'a'];
        
        for(const char c : s) {
            int idx = c - 'a';
            --cnts[idx];
            if(app[idx])
                continue;
            
            while(!res.empty() && cnts[res.back() - 'a'] && res.back() > c)
                app[res.back() - 'a'] = false, res.pop_back();
            app[idx] = true, res += c;
        }
        
        return res;
    }
};