//
//Runtime 0
//Memory Usage 8.5

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> res(n);
        sort(deck.begin(), deck.end());
        deque<int> q;
        for(int i = 0; i < n; ++i)
            q.push_back(i);
        int f = 1;
        int i = 0;
        while(q.size()){
            if(f){
                res[q.front()] = deck[i++];
                q.pop_front();
            }else{
                q.push_back(q.front());
                q.pop_front();
            }
            f = !f;
        }
        
        return res;
    }
};