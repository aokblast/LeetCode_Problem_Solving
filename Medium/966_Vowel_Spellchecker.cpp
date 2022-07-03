//
//Runtime 75
//Memory Usage 38.6

class Solution {
private:
    constexpr static int isvowel(int c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, string> mp1, mp2, org;
        for(const auto &word : wordlist){
            string w = word;
            
            org[w] = w;
            
            for(int i = 0; i < word.size(); ++i)
                w[i] = tolower(w[i]);
            
            if(mp1.find(w) == mp1.end())
                mp1[w] = word;
            
            for(int i = 0; i < word.size(); ++i)
                if(isvowel(w[i]))
                    w[i] = '*';
            
            if(mp2.find(w) == mp2.end())
                mp2[w] = word;
            
        }
        
        vector<string> res;
        
        for(auto &q : queries){
            if(org.find(q) != org.end()){
                res.push_back(q);
                continue;
            }
            
            for(int i = 0; i < q.size(); ++i)
                q[i] = tolower(q[i]);
            
            if(mp1.find(q) != mp1.end()){
                res.push_back(mp1[q]);
                continue;
            }
            
            for(int i = 0; i < q.size(); ++i)
                if(isvowel(q[i]))
                    q[i] = '*';
            
            if(mp2.find(q) != mp2.end()){
                res.push_back(mp2[q]);
                continue;
            }
            
            res.push_back("");
                
                
        }
        return res;
    }
};