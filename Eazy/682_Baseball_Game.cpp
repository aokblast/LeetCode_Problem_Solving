//
//Runtime 3
//Memory Usage 8.3
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> vals;
        for(const auto &op : ops){
            if(op == "+"){
                vals.push_back(vals[vals.size() - 1] + vals[vals.size() - 2]);
            }else if(op == "D"){
                vals.push_back(2 * vals.back());
            }else if(op == "C"){
                vals.pop_back();
            }else{
                vals.push_back(stoi(op));
            }
        }
        int res = 0;
        for(const int val : vals)
            res += val;
        return res;
    }
};