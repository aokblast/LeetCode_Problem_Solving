//
//Runtime 52
//Memory Usage  7.5
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
       while(true){
           int num = (rand7() - 1) * 7 + rand7();
           if(num <= 40)return num % 10 + 1;
       }
    }
};
