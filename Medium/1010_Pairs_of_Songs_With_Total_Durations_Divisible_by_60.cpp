//
//Runtime 24
//Memory Usgae 23.2

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> m;
        int res = 0;
        for(const int &t : time) ++m[t % 60];
        for(int i = 1; i < 30; ++i){
            if(m.find(i) != m.end() && m.find(60 - i) != m.end()) res += m[i] * m[60 - i];
        }
        res += m[30] * (m[30] - 1) / 2;
        res += m[0] * (m[0] - 1) / 2;
        res += m[60] * m[0];
        return res;
        
    }
};