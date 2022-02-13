//
//Runtime 0
//Memory Usage 6.5

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int num = left; num <= right; ++num){
            int tmp = num;
            bool ans = true;
            while(tmp){
                 if(tmp % 10 == 0 || num % (tmp % 10)){
                    ans = false;
                    break;
                }
                tmp /= 10;
            }
            if(ans)
                res.push_back(num);
        }
        return res;
    }
};