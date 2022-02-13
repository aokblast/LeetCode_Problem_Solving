//
//Runtime 68
//Memory Usage 20.5

class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        string res;
        queue<string> q;
        for(const auto &word : words)
            if(word.size() == 1)
                q.push(word);
        while(!q.empty()){
            int sz = q.size();
            res = q.front();
            while(sz--){
                string &s = q.front();
                res = min(res, s);
                for(char c = 'a'; c <= 'z'; ++c){
                    s.push_back(c);
                    if(st.find(s) != st.end()){
                        q.push(s);
                    }
                    s.pop_back();
                }
                q.pop();
            }
        }
        return res;
    }
};