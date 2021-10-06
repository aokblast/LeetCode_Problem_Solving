//
//Runtime 0 
//Memory Usage 6.2
class Solution {
public:
    string validIPAddress(string IP) {
        int num = 0, cnt = 0, hasNum = false;
        if(IP.find('.') != string::npos){
            for(char &c : IP){
                 if(c == '.' && hasNum){
                     if(num > 255){
                         return "Neither";
                     }else{
                         ++cnt;
                         num = 0;
                     }
                     hasNum = false;
                     
                 }else if(isdigit(c) && num <= 255){
                     if(hasNum && num == 0){
                         return "Neither";
                     }else{
                         num = num * 10 - '0' + c;
                     }
                     hasNum = true;
                 }else{
                     return "Neither";
                 }
            }
            return (cnt == 3 && num <= 255 && num >= 0 && hasNum) ? "IPv4" : "Neither";
        }else if(IP.find(':') != string::npos){
            for(char &c : IP){
                if(c == ':'){
                    ++cnt;
                    if(num > 4 || !hasNum){
                        return "Neither";
                    }
                    num = 0;
                    hasNum = false;
                 }else if(isdigit(c) || (tolower(c) >= 'a' && tolower(c) <= 'f') && num <= 4){
                    ++num;
                    hasNum = true;
                 }else{
                    return "Neither";
                }
            }
            return cnt == 7 && num <= 4 && hasNum? "IPv6" : "Neither";
        }else{
            return "Neither";
        }
    }
};
