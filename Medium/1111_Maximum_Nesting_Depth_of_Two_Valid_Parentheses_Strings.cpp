//
//Runtime 3
//Memory 7.3
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size(), level = 0;
        vector<int> res(n);
        
        for(int i = 0; i < n; ++i)
            if(seq[i] == '(')
                res[i] = level++ % 2;
            else
                res[i] = --level % 2;
        
        return res;
    }
};