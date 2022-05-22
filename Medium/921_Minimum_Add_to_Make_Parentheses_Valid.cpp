//greedy
//Runtime 0
//Memory Usage 6.1

class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0, lcnt = 0; 
        for(const char c : s){
            if(c == '(')
                ++lcnt;
            else{
                if(lcnt == 0)
                    ++res;
                else
                    --lcnt;
            }
        }
        return res + lcnt;
    }
};