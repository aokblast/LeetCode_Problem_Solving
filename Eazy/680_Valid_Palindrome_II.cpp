//
//Runtime 52
//Memory Usage 10.6

class Solution {
public:
    bool validPalindrome(string s) {
        int cnt = 1;
        int l = 0, r = s.size() - 1;
        while(l < r){
            if(s[l] == s[r]){
                ++l, --r;
                continue;
            }
            break;
        }
        if(l < r){
            if(s[l + 1] == s[r] && s[l] == s[r - 1]){
                
                int a = l, b = r;
                ++l;
                while(l < r){
                    if(s[l] == s[r]){
                        ++l, --r;
                        continue;
                    }
                    break;
                }
                if(l >= r)
                    return true;
                l = a, r = b;
                --r;
                while(l < r){
                    if(s[l] == s[r]){
                        ++l, --r;
                        continue;
                    }
                    break;
                }
                if(l >= r)
                    return true;
                else
                    return false;
            }else if(s[l + 1] == s[r]){
                ++l;
                while(l < r){
                    if(s[l] == s[r]){
                        ++l, --r;
                        continue;
                    }
                    break;
                }
                if(l >= r)
                    return true;
                else
                    return false;
            }else if(s[l] == s[r - 1]){
                
                --r;
                while(l < r){
                    if(s[l] == s[r]){
                        ++l, --r;
                        continue;
                    }
                    break;
                }
                if(l >= r)
                    return true;
                else
                    return false;
            }else{
                
                return false;
            }
            
            
            
            
        }else
            return true;
    }
};