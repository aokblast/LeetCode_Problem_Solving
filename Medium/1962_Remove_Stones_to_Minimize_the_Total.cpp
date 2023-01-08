//Greedy
//Runtime 665
//Memory Usage 105


class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;

        for(const int pile : piles)
            q.push(pile);

            int res = 0;

        while(k-- && q.size()) {
            int top = q.top(); q.pop();
            top -= top / 2;
            
            if(top == 0)
                continue;

            if(top == 1) {
                res += 1;
                continue;
            }
            
            q.push(top);
        }

        

        while(q.size()) 
            res += q.top(), q.pop();

        return res;
    }
};