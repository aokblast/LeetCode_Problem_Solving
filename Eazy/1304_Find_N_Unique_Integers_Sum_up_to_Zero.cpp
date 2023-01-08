//
//Runtime 0
//Memory Usage 6.8

class Solution {
public:
    vector<int> sumZero(int n) {
        int lim = n / 2;

        vector<int> res;

        for(int i = lim; i; --i)
            res.push_back(i), res.push_back(-i);
        
        if(n % 2)
            res.push_back(0);

        return res;
    }
};