//
//Runtime 3
//Memory Usage 7.4


class Solution {
public:
    bool canTransform(string start, string end) {
        int i = 0, j = 0;
        while(i < start.size() && j < end.size()){
            while(i < start.size() && start[i] == 'X')
                ++i;
            while(j < end.size() && end[j] == 'X')
                ++j;
            if(start[i] != end[j] || (start[i] == 'L' && i < j) || (start[i] == 'R' && i > j))
                return false;
            ++i, ++j;
        }
        while(i < start.size()){
            if(start[i] != 'X')
                return false;
            ++i;
        }
        while(j < end.size()){
            if(end[j] != 'X')
                return false;
            ++j;
        }
        return true;
        
    }
};
