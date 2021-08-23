//hash_map
//Runtime 4
//Memory Usage 6.9
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[128] = {0}, m2[128] = {0};
        int size = s.size();
        for(int i = 0; i < size; ++i){
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};
