//
//Runtime 0
//Memory Usage 6.2
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size(), m = goal.size();
        if(n != m)
            return false;
        s += s;
        return s.find(goal) != string::npos;
        
    }
};