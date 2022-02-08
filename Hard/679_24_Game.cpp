//
//Runtime 3
//Memory Usage 7.5
class Solution {
public:
    
    bool judgePoint24(vector<int>& cards) {
        char ops[] = {'+', '-', '*', '/'};
        auto get = [&](double a, double b, char op){
            switch(op){
                case '+':
                    return a + b;
                case '-':
                    return a - b;
                case '*':
                    return a * b;
                case '/':
                    return (b == 0) ? rand() % 1000 : a / b;
            }
            return 1.0;  
        };
        
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                if(i == j)
                    continue;
                for(int k = 0; k < 4; ++k){
                    if(k == i || k == j)
                        continue;
                    int l = 6 - i - j - k;
                    
                    for(int a = 0; a < 4; ++a)
                        for(int b = 0; b < 4; ++b)
                            for(int c = 0; c < 4; ++c){
                                double o1 = get(cards[i], cards[j], ops[a]);
                                double o2 = get(cards[k], cards[l], ops[c]);
                                if(abs(get(o1, o2, ops[b]) - 24.0) <= 0.00001)
                                    return true;
                                o1 = get(cards[j], cards[k], ops[b]);
                                o2 = get(o1, cards[l], ops[c]);
                                if(abs(get(cards[i], o2, ops[a]) - 24.0) <= 0.00001)
                                    return true;
                                o1 = get(cards[k], cards[l], ops[c]);
                                o2 = get(cards[j], o1, ops[b]);
                                if(abs(get(cards[i], o2, ops[a]) - 24.0) <= 0.00001)
                                    return  true;
                                o1 = get(cards[i], cards[j], ops[a]);
                                o2 = get(o1, cards[k], ops[b]);
                                if(abs(get(o2, cards[l], ops[c]) - 24.0) <= 0.00001)
                                    return true;
                                o1 = get(cards[j], cards[k], ops[b]);
                                o2 = get(cards[i], o1, ops[a]);
                                if(abs(get(o2, cards[l], ops[c]) - 24.0) <= 0.00001)
                                    return true;
                                o1 = get(cards[i], cards[j], ops[a]);
                                o2 = get(o1, cards[k], ops[b]);
                                if(abs(get(o2, cards[l], ops[c]) - 24.0) <= 0.00001)
                                    return true;
                                
                                
                            }
                                
                    
                    
                }
            }
        }
        return false;
    }
};