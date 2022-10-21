//Rolling Window
//Runtime 191
//Memory 95.4
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size(), res = 0, sum = 0;
        
        for(int i = 0; i < n;) {
            int j = i + 1;
            int mx = neededTime[i];
            sum = mx;
            
            while(j < n && colors[j] == colors[i])
                sum += neededTime[j], mx = max(neededTime[j], mx), ++j;
            
            if(i + 1!= j)
                res += sum - mx;
            
            i = j;
        }
        
        return res;
    }
};