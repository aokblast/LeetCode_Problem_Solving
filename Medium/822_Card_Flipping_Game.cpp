//
//Runtime 18
//Memory Usage 18.3

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int st[2005] = {0};
        int n = fronts.size();
        for(int i = 0; i < n; ++i){
            if(fronts[i] == backs[i])
                st[fronts[i]] = 2; 
            else
                st[fronts[i]] = max(st[fronts[i]], 1), st[backs[i]] = max(st[backs[i]], 1);
        }
        for(int num = 1; num <= 2000; ++num)
            if(st[num] == 1)
                return num;
        return 0;
                
    }
};