//
//Runtime 0 
//Memory Usage 5.9 
class Solution {
public:
    int nextGreaterElement(int n) {
        string ans;
        while(n){
            ans.push_back((n % 10) + '0');
            n /= 10;
        }
        reverse(ans.begin(), ans.end());
        if(next_permutation(ans.begin(), ans.end())){
            long long res = stol(ans);
            return res > INT_MAX ? -1 : res;
        }else{
            return -1;
        }
    }
};
