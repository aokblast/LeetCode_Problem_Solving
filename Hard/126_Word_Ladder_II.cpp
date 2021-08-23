//
//Runtime 12
//Memory Usage 11.7
class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wSet(wordList.begin(), wordList.end());
        if(wSet.find(endWord) == wSet.end()) return res;
        vector<string> path = {beginWord};
        queue<vector<string>> q;
        unordered_set<string> words;
        q.push(path);
        
        int level = 0, minLevel = INT_MAX;
        while(!q.empty()){
            auto top = q.front(); q.pop();
            if(top.size() > level){
                for(string s : words) wSet.erase(s);
                words.clear();
                level = top.size();
                if(level > minLevel) break;
            }
            string word = top.back();
            string newWord = word;
            for(int i = 0; i < word.size(); ++i){
                for(char c = 'a'; c <= 'z'; ++c){
                    newWord[i] = c;
                    if(wSet.find(newWord) == wSet.end()) continue;
                    words.insert(newWord);
                    vector<string> next = top;
                    next.push_back(newWord);
                    if(newWord == endWord){
                        res.push_back(next);
                        minLevel = level;
                    }else q.push(next);
                }
                newWord[i] = word[i];
            }
        }
        return res;
        
    }
};
