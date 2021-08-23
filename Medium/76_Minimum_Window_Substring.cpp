//Rolling Window
//Runtime 4
//Memory Usage 7.9
class Solution {
public:
    int ma[256];
    bool visit[256];
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        int cnt = 0;
        string result;
        int size = INT_MAX;
        for(char &c : t) {
            ++ma[c];
            if(ma[c] == 1)++cnt;
            visit[c] = true;
        }
        int left = 0, right  = 0;
        while(right < m){
            while(right < m){
                if(visit[s[right]]){
                    --ma[s[right]];
                    if(ma[s[right]]  == 0){
                        --cnt;
                    }
                    if(cnt == 0) break;
                    
                }
                ++right;
            }
            
            while(left < right){
                if(visit[s[left]]){
                    if(ma[s[left]] == 0){
                        break;
                    }
                    ++ma[s[left]];
                }
                ++left;
            }

            if(cnt == 0 && (right - left + 1) < size){
                result = s.substr(left, right - left + 1);
                size = right - left + 1;
            }
            
            
            ++ma[s[left]];
            ++left;
            ++right;
            ++cnt;
            
        }
        return result;
    }
};
