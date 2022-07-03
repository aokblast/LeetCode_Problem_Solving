//Greedy
//Runtime 48
//Memory Usage 17.3

class Solution {
public:
    int minDeletions(string s) {
        int cnts[26] = {0};
        
        for(const char c : s)
            ++cnts[c - 'a'];
        
        sort(cnts, cnts + 26);
        

        int res = 0;
        int i;
        for(i = 24; i >= 0; --i){
            if(cnts[i] == 0)
                break;
            if(cnts[i] >= cnts[i + 1]){
                int p = cnts[i];
                cnts[i] = max(cnts[i + 1] - 1, 0);
                res += p - cnts[i];;
            }
        }
        
        
        
        return res;
    }
};