//greedy
//Runtime 0
//Memory Usage 6.2

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.size(), xy = 0, yx = 0;
        
        for(int i = 0; i < n; ++i)
            if(s1[i] != s2[i])
                s1[i] == 'x' ? xy++ : yx++;
        
        if((xy + yx) % 2)
            return -1;
        
        return (xy + yx) / 2 + (xy % 2);
        
    }
};