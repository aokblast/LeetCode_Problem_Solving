//KMP
//Runtime 4
//Memory Usage 6.9

class Solution {
public:
    int f[10005] = {0};
    bool kmp(const string &s, const string &p){
        memset(f, 0, sizeof(f));
        int i = 0, j = -1;
        f[0] = -1;
        while(i < p.size()){
            if(j == -1 || p[i] == p[j])
                f[++i] = ++j;
            else
                j = f[j];
        }
        i = 0, j = 0;
        while(i < s.size()){
            if(j == -1 || s[i] == p[j]){
                ++j, ++i;
                if(j == p.size())
                    return true;
            }else
                j = f[j];
            
        }
        return false;
    }
    
    int repeatedStringMatch(string a, string b) {
        int n1 = a.size(), n2 = b.size();
        string t = a;
        int res = 1;
        while(t.size() < n2){
            t += a;
            ++res;
        }
        if(kmp(t, b))
            return res;
        t += a, ++res;
        if(kmp(t, b))
            return res;
        else
            return -1;
        
    }
};