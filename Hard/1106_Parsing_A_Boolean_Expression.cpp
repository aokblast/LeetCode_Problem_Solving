//dp
//Runtime 7
//Memory Usage 7.2
class Solution {
public:
    stack<char> op, st;
    void eval() {
        bool res = st.top() == 't';
        st.pop();
        if(op.top() == '!'){
            res = !res;
        }else {
            while(st.top() != '(') {
                bool cur = st.top() == 't';
                st.pop();
                switch(op.top()) {
                    case '&':
                        res &= cur;
                        break;
                    case '|':
                        res |= cur;
                        break;
                }
            }
        }
        st.pop();
        op.pop();
        st.push(res ? 't' : 'f');
    }
    bool parseBoolExpr(string expression) {
        for(const char ex : expression) {
            switch(ex) {
                case '|':
                case '&':
                case '!':
                    op.push(ex);
                    break;
                case '(':
                case 'f':
                case 't':
                    st.push(ex);
                    break;
                case ')':
                    eval();
                    break;
            }
        }
        return st.top() == 't';
    }
};