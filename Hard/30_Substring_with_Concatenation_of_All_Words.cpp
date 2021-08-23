//two hash map
//Runtime 420
//Memory Usage 12

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> wApp;
        for(auto &s : words) ++wApp[s];
        vector<int> result;
        int len = words[0].length();
        for(int i =  0; i <= (((int)s.length()) - len * (int)(words.size())); ++i){
            unordered_map<string, int> wLoc;
            int j;
            for(j = 0; j < words.size(); ++j){
                string w = s.substr(i + len * j, len);
                if(wApp.count(w) == 0) break;
                ++wLoc[w];
                if(wLoc[w] > wApp[w]) break;
                
            }
            if(j == words.size())  result.push_back(i);
        }
        return result;
    }
};

//rolling window
//Runtime 27
//Memory Usage 14

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> wLoc;
        vector<int> result;
        int max = (int)s.length() - (int)words.size() * words[0].size();
        int cnt = words.size();
        int len = words[0].size();
        for(auto &s : words) ++wLoc[s];
        for(int i = 0 ; i < words[0].length(); ++i){
            int front = i;
            int back = i;
            while(front <= max){
                string chunk = s.substr(back, len);
                if(wLoc.find(chunk) == wLoc.end()){
                    while(front < back){
                        ++wLoc[s.substr(front, len)];
                        ++cnt;
                        front += len;
                    }
                    back += len;
                    front = back;
                    continue;
                }
                if(wLoc[chunk] > 0){
                    --wLoc[chunk];
                    --cnt;
                    if(cnt == 0) result.push_back(front);
                    back += len;
                }else{
                    ++wLoc[s.substr(front, len)];
                    ++cnt;
                    front += len;
                }
            }
            
        }
        return result;
        
    }
};
