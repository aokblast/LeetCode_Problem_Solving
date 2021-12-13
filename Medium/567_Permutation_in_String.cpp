//Rolling Window
//Runtime 3
//Memory Usage 7.3

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> m(128);
        int k = 0;
        for(const char &c :  s1){
            k += (m[c]++) == 0;
        }
        int l = 0, r = 0, n = s1.size();
        while(r < s2.size()){
            while(r < s2.size() && (r - l) < n){
                k -= (--m[s2[r++]] == 0);
            }
            if(k == 0)return true;
            k += (++m[s2[l++]] == 1);
            
        }
        return false;
        
    }
};