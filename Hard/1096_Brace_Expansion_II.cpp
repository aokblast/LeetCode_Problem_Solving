//stack
//Runtime 45
//Memory Usage 10
class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        unordered_set<string> res;
        stack<string> stk;
        
        stk.push(expression);
        
        while(!stk.empty()) {
            string top = stk.top(); stk.pop();
            auto pos = top.find('}');
            if(pos == string::npos) {
                res.insert(top);
            }else{
                int l = 0, r = pos - 1, cur = r;
                while(top[cur] != '{')
                    --cur;
                l = cur + 1;
                string a = top.substr(0, l - 1);
                string b = top.substr(r + 2, top.size() - r + 2 -1);
                string mid = top.substr(l, r - l + 1);
                stringstream ss(mid);
                string tmp;
                while(getline(ss, tmp, ','))  {
                    stk.push(a + tmp + b);
                }

            }
        }
        
        vector<string> tmp(res.begin(), res.end());
        sort(tmp.begin(), tmp.end());
        
        return tmp;
    }
};