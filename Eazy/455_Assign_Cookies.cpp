//Greedy
//Runtime 20
//Memory Usage 17.5

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gSize = g.size();
        int sSize = s.size();
        int j = 0;
        int total  =0, minus = 0;;
        for(int i = 0 ; i  < gSize && j < sSize;){
            if(g[i] <= s[j]) ++i, ++j, ++total;
            else ++j;
            
        }
        return total;
    }
};
