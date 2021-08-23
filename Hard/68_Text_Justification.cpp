//
//Runtime 0
//Memory Usage 7.5
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i = 0;
        int size = words.size();
        vector<string> result;
        while(i < size){
            int j = i;
            int s = 0;
            while(j < size && s + words[j].size() + j - i <= maxWidth){
                s += words[j].size();
                ++j;
            }
            int space = maxWidth - s;
            string newLine;
            for(int k = i; k < j; ++k){
                newLine += words[k];
                int cnt = 0;
                if(size == j){
                    if(k == size - 1) cnt = space;
                    else cnt = 1;
                }else{
                    if(k == j - 1) cnt = space;
                    else{
                       cnt = ceil(((double)space) / (j - k - 1)); 
                    }
                }
                newLine.append(cnt, ' ');
                space -= cnt;
            }
            i = j;
            result.push_back(newLine);
            
        }
        return result;
    }
};
