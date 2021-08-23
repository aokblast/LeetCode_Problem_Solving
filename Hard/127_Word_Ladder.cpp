//bfs
//Runtime 72 
//Memory Usage 13.7
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wSet(wordList.begin(), wordList.end());
        if(wSet.find(endWord) == wSet.end()) return 0;
        int ans = 1;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
            string word = q.front(); q.pop();
            string newWord = word;
            int size = word.size();
            for(int i = 0; i < size; ++i){
                for(char c = 'a'; c <= 'z'; ++c){
                    newWord[i] = c;
                    if(wSet.find(newWord) == wSet.end()) continue;
                    if(newWord == endWord) return ans + 1;
                    else{
                        q.push(newWord);
                        wSet.erase(newWord);
                    } 
                    }
                    newWord[i] = word[i];
                }
            }
            ++ans;
        }
        return 0;
    }
};
