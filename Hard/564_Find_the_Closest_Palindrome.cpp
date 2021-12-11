//
//Runtime 0 
//Memory Usage 6.5
class Solution {
public:
    string nearestPalindromic(string n) {
        long num = stol(n), res = -1;
        int len = n.size();
        unordered_set<long> s;
        s.insert(pow(10, len) + 1);
        s.insert(pow(10, len - 1) - 1);
        long pref = stol(n.substr(0, (len + 1) / 2));
        for(int i = -1; i <= 1; ++i){
            string pre = to_string(pref + i);
            s.insert(stol(pre + string(pre.rbegin() + (len & 1), pre.rend() )));
        }
        s.erase(num);
        for(const long &nu : s){
            if(abs(nu - num) == abs(res - num)){
                res = min(res, nu);
            }
            if(abs(nu - num) < abs(res - num)){
                res = nu;
            }
        }
        return to_string(res);
    }
};
