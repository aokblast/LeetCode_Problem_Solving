//
//Runtime 5
//Memory Usage 7.3
class Solution {
public:
    string sortString(string s) {
        int app[26] = {0};

        for(const char c : s)
            ++app[c - 'a'];

        string res;

        while(true){

            bool has = false;
            for(int i = 0; i < 26; ++i)
                if(app[i])
                    res += (char)'a' + i, --app[i], has = true;
            if(!has)
                break;
            
            has = false;

            for(int i = 25; i >= 0; --i)
                if(app[i])
                    res += (char)'a' + i, --app[i], has = true;
            if(!has)
                break;
        }
        
        return res;
    }
};