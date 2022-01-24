//
//Runtime 4
//Memory 6.9
class Solution {
public:
    string predictPartyVictory(string senate) {
        bool r = true, d = true;
        int has = 0;
        while(r && d){
            r = d = false;
            for(char &c : senate){
                if(c == 'R'){
                    if(has < 0)c = '0';
                    else r = true;
                    ++has;
                }
                if(c == 'D'){
                    if(has > 0)c = '0';
                    else d = true;
                    --has;
                }
            }
        }
        return r ? "Radiant" : "Dire";
        
    }
};