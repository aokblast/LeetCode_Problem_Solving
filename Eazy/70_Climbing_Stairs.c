// Method 1(Failed)

int step(int cur, int target) {
    if(target - cur == 3) return 3;
    else if(target - cur == 2) return 2;
    else if(target - cur == 1) return 1;
    else return step(cur+1,target)+step(cur+2,target);
}

int climbStairs(int n){
    return step(0,n);
}

// Method 2(100, 66.73)

int climbStairs(int n){
    if (n <= 3) return n;
    int i = 3;
    int step1 = 1, step2 = 2, step3 = 3;
    while (i <= n ){
        step3 = step1 + step2;
        step1 = step2;
        step2 = step3;
        i++;
    }
    
    return step3;
}