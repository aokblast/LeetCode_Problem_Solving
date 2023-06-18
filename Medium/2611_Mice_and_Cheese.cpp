//
//Runtime 171
//Memory Usage 104.9

    class Solution {
    public:
        int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
            int res = 0;
            priority_queue<int,vector<int>,greater<int>> pq;
            for(int i = 0; i < reward1.size(); i++){
                res += reward2[i];
                res += (reward1[i]-reward2[i]);
                pq.push(reward1[i]-reward2[i]);
                if(pq.size()>k){
                    res -= pq.top();
                    pq.pop();
                }
            }
            return res;
        }
    };