//Greedy
//Runtime 41
//Memory Usage 18.9

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        vector<pair<int, int>> vs(n);
        
        int lim = 0;
        
        for(int i = 0; i < n; ++i)
            vs[i] = {values[i], labels[i]}, lim = max(lim, labels[i]);
        
        sort(vs.begin(), vs.end(), greater());
        
        int cnts[lim + 1];
        memset(cnts, 0, sizeof(cnts));
        
        int res = 0, cur = 0;
        
        for(const auto [val, lab] : vs) 
            if(cnts[lab] < useLimit) {
                ++cnts[lab], res += val;
                if(++cur == numWanted)
                    break;
            }
        return res;
            
        
    }
};