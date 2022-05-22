//
//Runtime 0
//Memory Usage 6.4

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int l = 0, r = 0;
        while(l < name.size() && r < typed.size()){
            if(name[l] == typed[r])
                ++l, ++r;
            else if(r > 0 && typed[r] == typed[r - 1])
                ++r;
            else
                break;
        }
        
        while(r < typed.size() && r > 0 && typed[r] == typed[r - 1])
            ++r;
        
        return l == name.size() && r == typed.size();
    }
};