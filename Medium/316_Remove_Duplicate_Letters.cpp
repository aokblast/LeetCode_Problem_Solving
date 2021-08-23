//Greedy + Monotonous Stack
//Runtime 0
//Memory Usage 6.8


class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> app;
        unordered_map<char, bool> visit;
        string result;
        for(char &c : s) {
            ++app[c];
        }
        for(char &c : s){
            --app[c];
            if(visit[c]) continue;
            while(!result.empty() && result.back() > c && app[result.back()] > 0){
                visit[result.back()] = false;
                result.pop_back(); 
            }
            result.push_back(c);
            visit[c] = true;
        }
        
        return result;
    }
};
