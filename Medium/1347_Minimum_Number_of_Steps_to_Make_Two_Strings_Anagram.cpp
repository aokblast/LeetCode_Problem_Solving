//Greedy
//Runtime 48
//Memory Usage 16.6

class Solution {
public:
    int minSteps(string s, string t) {
        int mp[26] = {0};

        for(const char c : s)
            mp[c - 'a']++;
        
        for(const char c : t) 
            mp[c - 'a']--;

        int sum = 0;

        for(int i = 0; i < 26; ++i)
            sum += abs(mp[i]);
        
        return sum / 2;
    }
};