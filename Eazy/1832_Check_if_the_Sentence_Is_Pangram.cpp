//Runtime 0
//Memory Usage 6.3
class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool app[26] = {false};
        
        for(const char c : sentence)
            app[c - 'a'] = true;
        
        for(const bool b : app)
            if(!b)
                return false;
        return true;
    }
};