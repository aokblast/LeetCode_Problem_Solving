//
//Runtime 46
//Memory Usage 17.9

class MagicDictionary {
public:
    vector<string> v;
    
    
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dict) {
        v = dict;
    }
    
    bool search(string searchWord) {
        for(const auto &s :v){
            if(s.length() == searchWord.length()){
                int dif = 0;
                for(int i = 0; i < s.size(); ++i){
                    dif += s[i] != searchWord[i];
                    if(dif > 1)
                        break;
                }
                if(dif == 1)
                    return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */