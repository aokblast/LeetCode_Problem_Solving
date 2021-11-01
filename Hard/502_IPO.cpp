//Greedy
//Runtime 252 
//Memory Usage 84.4
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        
        bool hasN = true;
        for(const int &c  : capital){
            if(c > w){
                hasN = false;
                break;
            }
        }
        if(hasN){
            vector<int> v;
            for(const int &p : profits){
                v.push_back(p);
            }
            sort(v.begin(), v.end());
            for(int i = n - 1; i >= n - k; --i){
                w += v[i];
            }
            return w;
            
        }
        vector<pair<int, int>> q;
        priority_queue<pair<int, int>> maq;
        for(int i = 0; i < n; ++i){
            q.push_back({capital[i], profits[i]});
        }
        sort(q.begin(), q.end());
        
        int idx = 0;
        while(k--){
            while(idx < n && q[idx].first <= w){
                
                maq.push({q[idx].second, q[idx].first});
                ++idx;
            }
            if(maq.empty())break;
            w += maq.top().first;maq.pop();
        }
        return w;
    }
};
