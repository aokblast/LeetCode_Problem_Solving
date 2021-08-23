//KMP
//Runtime 4
//Memory Usage 7.4

class Solution {
public:
    int f[50000];
    void failureFunc(string &pat){
        int lenn = pat.size();
        f[0] = -1;
        int i = 0, j = -1;
        while(i < lenn){
            if(j == -1 || pat[i] == pat[j]){
                ++i, ++j;
                f[i] = j;
            }else{
                j = f[j];
            }
         }
    }
    
    
    int strStr(string haystack, string needle) {
        failureFunc(needle);
        int i = 0, j = 0;
        int lenh = haystack.size(), lenn = needle.size();
        while(i < lenh && j < lenn){
            
            if(j == -1 || haystack[i] == needle[j])++i, ++j;
            else j = f[j];
        }
        return j == lenn ? i - j : -1;
    }
};
