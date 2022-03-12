//
//Runtime 0
//Memory Usage 8.4

static const char *mp[] = {
    ".-",   //A
    "-...", //B
    "-.-.", //C
    "-..",  //D
    ".",    //E
    "..-.", //F
    "--.",  //G
    "....", //H
    "..",   //I
    ".---", //J
    "-.-",  //K
    ".-..", //L
    "--",   //M
    "-.",   //N
    "---",  //O
    ".--.", //P
    "--.-", //Q
    ".-.",  //R
    "...",  //S
    "-",    //T
    "..-",  //U
    "...-", //V
    ".--",  //W
    "-..-", //X
    "-.--", //Y
    "--..", //Z
};
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> s;
        string tmp;
        for(const auto &word : words){
            tmp.clear();
            for(const char c : word){
                tmp += mp[c - 'a'];
            }
            s.insert(tmp);
        }
                
        
        return s.size();
    }
};