//
//Runtime 0
//Memory Usage 6
class Solution {
public:
    int arr[50] = {0};
    int strongPasswordChecker(string password) {
        bool l = true, u = true, d = true;
        int n = password.length();
        for(int i = 0; i < n;){
            if(islower(password[i]))l = false;
            if(isupper(password[i]))u = false;
            if(isdigit(password[i]))d = false;
            int j = i;
            while(i < n && password[j] == password[i]) ++i;
            arr[j]  = i - j;
        }
        int miss = l + u + d;
        int ans = 0;

        if(n < 6)ans += miss + max(0, 6 - miss - n);
        else{
            int ol = max(0, n - 20), rep = 0;
            ans += ol;
            for(int k = 1; k < 3; ++k){
                for(int i = 0; i < n && ol > 0; ++i){
                    if(arr[i] < 3 || arr[i] %3 != (k - 1))continue;
                    arr[i] -= min(ol, k);
                    ol -= k;
                }
            }
            for(int i = 0; i < n; ++i){
                if(arr[i] >= 3 && ol > 0){
                    int need = arr[i] - 2;
                    arr[i] -= ol;
                    ol -= need;
                }
                if(arr[i] >= 3)rep += arr[i] / 3;
            }
            ans += max(miss, rep);
        }
        return ans;
    }
};
