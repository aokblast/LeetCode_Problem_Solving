//
//Runtimei 4
//Memory Usage 6.9
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream in(preorder);
        string tmp;
        int cnt = 1;
        while(getline(in, tmp, ',')) {
            if(!cnt) return false;
            cnt += ((tmp == "#") ? -1 : 1);
        }
        return !cnt;

    }
};
