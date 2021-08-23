//
//Runtime 8
//Memory Usage 17.5
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int minN = 0;
        unordered_map<int, int> ma;
        for(int &c : deck){
            ++ma[c];
        }
        for(auto &c : ma){
            minN = gcd(minN, c.second);
        }
        if(minN < 2) return false;
        return true;
    }
};
