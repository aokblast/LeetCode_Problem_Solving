//dp
//Runtime 0
//Memory Usgae 6.3

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int p = 1;
        vector<int> res;
        
        while(p <= label) 
            p <<= 1;

        
        while(p > 1) {
            res.push_back(label);
            label = (p - 1 - label) / 2 + ((p >> 1) - (p >> 2)); 
            p >>= 1;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};