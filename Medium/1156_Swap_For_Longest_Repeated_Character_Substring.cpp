//
//Runtime 2
//Memory Usage 7.7

class Solution {
public:
    int maxRepOpt1(string text) {
        vector<int> idxs[26];
        
        for(int i = 0; i < text.size(); ++i)
            idxs[text[i] - 'a'].push_back(i);
        
        int res = 1;
        for(const auto &idx : idxs) {
            int b1 = 1, b2 = 0, mx = 0;
            for(int i = 1; i < idx.size(); ++i) {
                if(idx[i] == idx[i - 1] + 1)
                    ++b1;
                else
                    (b2 = (idx[i] == idx[i - 1] + 2) ? b1 : 0), b1 = 1;
                mx = max(mx, b1 + b2);
            }
            res = max(res, mx + (idx.size() > mx ? 1 : 0));
        }
        
        return res;
    }
};