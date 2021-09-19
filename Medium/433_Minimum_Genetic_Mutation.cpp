//
//Runtime 0
//Memory Usage 6.6
class Solution {
public:
    vector<int> adjs[50];
    bool visit[50] = {false};
    int minMutation(string start, string end, vector<string>& bank) {
        int s = -1, t = -1;
        if(find(bank.begin(), bank.end(), start) == bank.end())bank.push_back(start);
        int n = bank.size();

        for(int i = 0; i < n; ++i){
            if(start == bank[i]) s= i;
            if(end == bank[i]) t = i;
            for(int j = i + 1; j < n; ++j){
                int diff = 0;
                for(int k = 0; k < 8; ++k){
                    diff += bank[i][k] != bank[j][k];
                }
                if(diff == 1){
                    adjs[i].push_back(j);
                    adjs[j].push_back(i);
                   
                }
            }
        }
        if(!~t)return -1;
        int ans = 0;
        queue<int> q;
        q.push(s);
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int tu = q.front();q.pop();
                if(tu == t) return ans;
                if(visit[tu]) continue;
                visit[tu] = true;
                for(int &id : adjs[tu])if(!visit[id]) q.push(id);
            }
            ++ans;
            
        }
        return -1;
        
    }
};
