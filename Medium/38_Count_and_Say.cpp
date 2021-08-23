// 
//Runtime 8
//Memory Usage 6.6

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        n-= 1;
        while(n--){
            string tmp;
            int size = result.size();
            for(int i = 0; i < size; ++i){
                int cnt = 0;
                while(i < size && result[i + 1] == result[i]){
                    ++cnt;
                    ++i;
                }
                ++cnt;
                tmp += to_string(cnt) + result[i];
            }
            result = tmp;
        }
        return result;
    }
};
