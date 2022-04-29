//priority_queue
//Runtime 0
//Memory Usage 7.7

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(const int stone : stones)
            q.push(stone);
        while(q.size() > 1){
            int t1 = q.top(); q.pop();
            int t2 = q.top(); q.pop();
            if(t1 - t2)
                q.push(t1 - t2);
            
        }
        return q.empty() ? 0 : q.top();
    }
};