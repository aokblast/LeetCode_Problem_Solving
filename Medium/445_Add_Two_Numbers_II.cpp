//
//Runtime 4
//Memory Usage 9
class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0, n = chars.size();
        for(int i = 0; i < n;){
            int j = i + 1;
            for(; j < n && chars[i] == chars[j]; ++j){}
            if((j - i) > 1) {
                string num = to_string((j - i));
                chars[ans++] = chars[i];
                for(char &c : num){
                    chars[ans++] = c;
                }
                
            }
            else {
                chars[ans++] = chars[i];
            }
            i = j;
        }
        return ans;
    }
};
