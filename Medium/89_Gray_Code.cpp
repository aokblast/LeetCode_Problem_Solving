//
//Runtime 4
//Memory Usage 12.3
class Solution {
public:
    vector<int> result;
    vector<int> grayCode(int n) {
        long long lim = pow(2, n);
        for(int i = 0; i < lim; ++i){
            result.push_back((i >> 1) ^ i);
        }
        return result;
    }
};
