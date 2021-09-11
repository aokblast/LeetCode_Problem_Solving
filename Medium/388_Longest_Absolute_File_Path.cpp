//
//Runtime 0
//Memory Usage 6.7
class Solution {
public:
    int lengthLongestPath(string input) {
        stringstream ss(input);
        int ans = 0;
        unordered_map<int, int> m = {{0, 0}};
        string item;
        while(getline(ss, item)){
            int l = item.find_last_of('\t') + 1;
            int len =  item.substr(l).size();
            if(item.find('.') != string::npos){
                ans = max(ans, m[l] + len);
                
            }else{
                m[l + 1] = m[l] + len + 1;
            }
        }
        return ans;
    }
};
