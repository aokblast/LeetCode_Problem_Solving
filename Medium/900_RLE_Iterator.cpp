//
//Runtime 9
//Memory Usage 8.6

class RLEIterator {
public:
    RLEIterator(vector<int>& encoding) {
        code = encoding;
        idx += 2;
        cur = encoding[1];
        rem = encoding[0];
    }
    
    int next(int n) {
        while(n){
            if(idx == code.size() && rem == 0)
                return -1;
            if(rem >= n){
                rem -= n;
                break;
            }else{
                n -= rem;
                if(idx == code.size()){
                    rem = 0;
                    return -1;
                }
                rem = code[idx];
                cur = code[idx + 1];
                idx += 2;
            }
        }
        int res = cur;
        if(rem == 0){
            if(idx == code.size()){
                    rem = 0;
                    
            }else{
                rem = code[idx];
                cur = code[idx + 1];
                idx += 2;
            }
        }
        return res;
    }
    vector<int> code;
    int idx = 0;
    int cur = 0;
    int rem = 0;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
