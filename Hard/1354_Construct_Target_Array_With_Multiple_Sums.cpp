//
//Runtime 41
//Memory Usage 30.1

class Solution {
public:
    bool isPossible(vector<int>& target) {
        unsigned sum = 0;
        priority_queue<int> q;
        
        for(const int num : target)
            q.push(num), sum += num;
        
        while(q.top() != 1){
            int t = q.top(); q.pop();
            
            sum -= t;
            
            if(t <= sum || sum < 1)
                return false;
            
            t %= sum;
            sum += t;
            q.push(t ? t : sum);
            
        }
        return true;
    }
};