// 
//Runtime 0
//Memory Usage 6.3

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> pre, cur;
        for(int i = 0; i < s.size(); ++i){
            switch(s[i]){
                case '(':
                    pre.push(i);
                    break;
                case ')':
                    if(pre.empty() && cur.empty())
                        return false;
                    if(!pre.empty())
                        pre.pop();
                    else
                        cur.pop();
                    break;
                case '*':
                    cur.push(i);
                    break;
            }
        }
        while(!pre.empty()){
            if(cur.empty())
                return false;
            int a = pre.top(), b = cur.top();
            pre.pop(), cur.pop();
            if(a > b)
                return false;
        }
        return true;
    }
};