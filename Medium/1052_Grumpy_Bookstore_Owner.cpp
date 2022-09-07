//Sliding Windows
//Runtime 48
//Memory Usage 31.9

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int cur = 0, sum = 0, mx = 0, n = customers.size();
        
        for(int i = 0; i < minutes; ++i)
            if(grumpy[i])
                cur += customers[i];
            else
                sum += customers[i];
        
        mx = cur;
        
        for(int i = minutes; i < n; ++i) {
            if(grumpy[i])
                cur += customers[i];
            else
                sum += customers[i];
            if(grumpy[i - minutes])
                cur -= customers[i - minutes];
            mx = max(mx, cur);
        }
        return sum + mx;
    }
};