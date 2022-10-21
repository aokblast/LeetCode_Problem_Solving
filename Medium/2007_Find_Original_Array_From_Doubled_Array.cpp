//Greedy
//Runtime 374
//Memory Usage 119.6

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        sort(changed.begin(), changed.end(), greater());
        
        
        int cnts[100005] = {0};
        vector<int> res;
        
        if(n % 2)
            return {};
       
        
        for(int i = 0; i < n; ++i) {
            if(changed[i] * 2 <= 1e5 && cnts[changed[i] * 2])
                res.push_back(changed[i]), cnts[changed[i] * 2]--;
            else
                cnts[changed[i]]++;
        }
        
        return res.size() == n / 2 ? res : vector<int>();
        
    }
};