//
//Runtime 0
//Memory Usage 6.3
class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        string tmp; 
        int ans = 0;
        while(ss >> tmp){
            ++ans;
        }
        return ans;
    }
};
