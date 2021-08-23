//
//Runtime 0
//Memory 5.8
class Solution {
public:
    int fraction(int num){
        return num <= 1 ? 1 : num * fraction(num - 1);
    }
    string getPermutation(int n, int k) {
        string result;
        for(int i = 1; i <= n; ++i) result += i + '0';
        for(int i = 0; i < n - 1; ++i){
            int tmp = (k - 1) / fraction(n - i - 1);
            
            k -= tmp * fraction(n - i - 1);
            result.push_back(result[tmp]);
            result.erase(result.begin() + tmp);
        }
        result.push_back(result[0]);
        result.erase(result.begin());
        return result;
    }
};
