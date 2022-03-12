//
//Runtime 0
//Memory Usage 5.9

class Solution {
public:
    int rotatedDigits(int n) {
        int res = 0;
        auto valid = [](int num){
            return num == 7 || num == 4 || num == 3;
        };
        int mp[] = {0, 1, 5, 0, 0, 2, 9, 0, 8, 6};
        int pow[] = {1, 10, 100, 1000, 10000};
        for(int i = 1; i <= n; ++i){
            bool isV = true;
            int j = i, tmp = 0, cnt = 0;
            while(j){
                if(valid(j % 10)){
                    isV = false;
                    break;
                }
                tmp += mp[j % 10] * pow[cnt++];
                j /= 10;
            }
            res += isV && i != tmp;
            
        }
        return res;
    }
};