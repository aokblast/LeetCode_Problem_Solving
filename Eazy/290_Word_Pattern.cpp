//hash_map
//Runtime 0
//Memory 6.5
class Solution {
public:
    unordered_map<char, int> m1;
    unordered_map<string, int> m2;
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        int n = pattern.size();
        int i  =0;
        string su;
        for(; ss >> su; ++i){
            if(i == n || m1[pattern[i]] != m2[su]) return false;
            m1[pattern[i]] = m2[su] = i + 1;
        }
        return i == n;
    }
};
