//Greedy
//Runtime 23
//Memory Usage 13.6


class Solution {
public:
    int minPartitions(string n) {
        char res = 0;
        
        for(const char c : n){
            res = max(res, c);
            if(res == '9')
                break;
        }
        
        return res - '0';
    }
};