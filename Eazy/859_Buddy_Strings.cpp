//Runtime 4
//Memory Usage 7
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.size();
        char a1[2], a2[2];
        int idx = 0;
        if(s.size() != goal.size())
            return false;
        if(s == goal){
            int arr[26] = {0};
            for(int i = 0; i < n; ++i){
                if(++arr[s[i] - 'a'] >= 2)
                    return true;
            }
            return false;
        }
        for(int i = 0; i < n; ++i){
            if(s[i] != goal[i]){
                if(idx >= 2)
                    return false;
                a1[idx] = s[i];
                a2[idx] = goal[i];
                ++idx;
            }
        }
        return idx == 2 && (a1[0] == a2[1] && a1[1] == a2[0]);
    }
};