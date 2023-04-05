//Greedy
//Runtime 163
//Memory Usage 55.9

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> e;

        for(const auto &s : reservedSeats)
            e[s[0] - 1] |= 1 << (s[1] - 1);
        
        int res = 0;

        const int l = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4);
        const int r = (1 << 5) | (1 << 6) | (1 << 7) | (1 << 8);
        const int m = (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);

        for(auto &a : e) {

            if((a.second & l) == 0)
                ++res, a.second |= l;
            
            if((a.second & r) == 0)
                ++res, a.second |= r;
            
            if((a.second & m) == 0)
                ++res, a.second |= m;
        }

        return res + (n - e.size()) * 2;
    }
};