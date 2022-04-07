//sort
//Runtime 0
//Memory Usage 6

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string r  = to_string(n);
        sort(r.begin(), r.end());
        for(int i = 0; i < 32; ++i){
            string n2 = to_string(1 << i);
            sort(n2.begin(), n2.end());
            if(n2 == r)
                return true;
        }
        return false;
        
    }
};