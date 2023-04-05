//
//Runtime 13
//Memory Usage 9.2

    class Solution {
    public:
        int minNumberOfFrogs(string croakOfFrogs) {
            int res = 0;
            
            int c, r, o, a, k;
            c = r = o = a = k = 0;
            int cur = 0;

            for(const auto cro : croakOfFrogs) {
                switch(cro) {
                    case 'c':
                        ++cur;
                        ++c;
                        break;
                    case 'r':
                        ++r;
                        break;
                    case 'o':
                        ++o;
                        break;
                    case 'a':
                        ++a;
                        break;
                    case 'k':
                        ++k;
                        --cur;
                        break;
                }

                if(c < r || r < o || o < a || a < k)
                    return -1;

                res = max(res, cur);
            }

            if(c != r || r != o || o != a || a !=k)
                return -1;

            return res;
        }
    };