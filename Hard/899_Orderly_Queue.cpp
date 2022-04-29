//
//Runtime 3
//Memory 10.8
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1){
            sort(s.begin(), s.end());
            return s;
        }else{
            string res(s.size(), 'z');
            for(int i = 0; i < s.size(); ++i){
                string tmp = s.substr(i + 1) + s.substr(0, i + 1);
                res = min(res, tmp);
            }
            return res;
        }
    }
};