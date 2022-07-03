//
//Runtime 3
//Memory Usage 9.5

class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        int app[10] = {0};
        for(const int num : arr)
            app[num]++;
        if(app[2]){
            --app[2];
            for(int i = 3; i >= 0; --i){
                if(app[i]){
                    --app[i];
                    for(int j = 5; j >= 0; --j){
                        if(app[j]){
                            --app[j];
                            for(int k = 9; k >= 0; --k){
                                if(app[k]){
                                    return string() + (char)(2 + '0') + (char)(i + '0') + ':' + (char)(j + '0') + (char)(k + '0');
                                }
                            }
                            ++app[j];
                        }
                    }
                    ++app[i];
                }
            }
            ++app[2];
        }
        for(int i = 1; i >= 0; --i){
            if(app[i]){
                --app[i];
                for(int j = 9; j >= 0; --j){
                    if(app[j]){
                        --app[j];
                        for(int k = 5; k >= 0; --k){
                            if(app[k]){
                                --app[k];
                                for(int l = 9; l >= 0; --l){
                                    if(app[l]){
                                        return string() + (char)(i + '0') + (char)(j + '0') + ':' + (char)(k + '0') + (char)(l + '0');
                                    }
                                }
                                ++app[k];
                            }
                        }
                        ++app[j];
                    }
                }
                ++app[i];
            }
        }
        return "";
        
    }
};