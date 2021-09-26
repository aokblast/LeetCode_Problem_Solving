//
//Runtime 8
//Memory Usage 8.5
class Solution {
public:
    map<char, int> freq;
    priority_queue<pair<int, char>> q;
    string frequencySort(string s) {
        for(const char &c : s){
            ++freq[c];
        }
        for(auto &p : freq){
            q.push({p.second, p.first});
        }
        string ans;
        while(!q.empty()){
            auto top = q.top();
            while(top.first--){
                ans += top.second;
            }
            q.pop();
        }
            
    
        return ans;
    }
};
