//
//Runtime 0
//Memory Usage 7

class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        unordered_set<int> st;
        st.insert(0);

        for(const auto p: path) {
            switch(p) {
                case 'N':
                    ++x;
                    break;
                case 'E':
                    ++y;
                    break;
                case 'S':
                    --x;
                    break;
                case 'W':
                    --y;
                    break;
                default:
                    exit(1);
            }

            int enc = x * 10000 + y;
            if(st.count(enc))
                return true;
            st.insert(enc);
        }

        return false;
    }
};