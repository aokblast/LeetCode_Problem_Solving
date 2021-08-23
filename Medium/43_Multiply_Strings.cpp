//
//Runtimer 4
//Memory Usage 6.5

class Solution {
public:
    int arr[500];
    string multiply(string num1, string num2) {
        for(int i = num1.size() - 1; i >= 0; --i){
            for(int j = num2.size() - 1; j >= 0; --j){
                arr[i +j + 1] += (num1[i] - '0') * (num2[j] - '0');
                int offset = 0;
                while(arr[i + j + offset + 1] >= 10){
                    arr[i + j + offset] += arr[1 + i + j + offset] / 10;
                    arr[i + j + offset + 1] %= 10;
                    --offset;
                }
            }
        }
        string result;
        int start = 0;
        while(arr[start] == 0 && start < num1.size() + num2.size()) ++start;
        for(int i = start; i < num1.size() + num2.size() ; ++i )result += '0' + arr[i];
        return result.empty() ? "0" : result;
    }
};
