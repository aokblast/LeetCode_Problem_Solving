//Greedy
//Runtime 21
//Memory Usgae 11.4

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int mp1[26] = {0}, mp2[26] = {0};

        for(const char c : s1)
            mp1[c - 'a']++;

        for(const char c : s2)
            mp2[c - 'a']++;


        int dir = mp1[25] > mp2[25] ? 1 : mp1[25] < mp2[25] ? -1 : 0;
            

        for(int i = 24; i >= 0; --i) { 
            mp1[i] += mp1[i + 1];
            mp2[i] += mp2[i + 1];

            if(mp1[i] > mp2[i]) {
                if(dir == -1)
                    return false;
                else if(dir == 0)
                    dir = 1;
            } else if(mp1[i] < mp2[i]) {
                if(dir == 1)
                    return false;
                else if(dir == 0)
                    dir = -1;
            }
        }

        return true;
    }
};