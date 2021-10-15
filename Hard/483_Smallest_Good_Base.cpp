//
//Runtime 0 
//Memory Usage 6.3
class Solution {
public:
    string smallestGoodBase(string n) {
        long long int num = stol(n);
        for(int term = log2(num + 1); term >= 2; --term){
            long long left = 2, right = pow(num, 1.0 / (term - 1)) + 1;
            while(left < right){
                long long mid = left + ((right - left) >> 1), sum = 0;
                for(int i = 0; i < term; ++i){
                    sum = sum * mid + 1;
                }
                
                if(sum == num)return to_string(mid);
                else if(sum < num) left = mid + 1;
                else right = mid - 1;
            }

        }
        return to_string(num - 1);
    }
};
