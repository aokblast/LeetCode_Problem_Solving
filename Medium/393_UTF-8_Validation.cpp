//
//Runtime 12
//Memory Usage 14.1
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for(const int &d : data){
            if(cnt){
                if((d >> 6) != 0b10)return false;
                --cnt;    
            }else{
                if((d >> 5) == 0b110)cnt = 1;
                else if((d >> 4) == 0b1110) cnt = 2;
                else if((d >> 3) == 0b11110) cnt = 3;
                else if((d >> 7)) return false;
            }
        }
        return !cnt;
    }
};
