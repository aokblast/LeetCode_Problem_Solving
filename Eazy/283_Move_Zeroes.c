// Method 1 (92.94,22.13)

void moveZeroes(int* nums, int numsSize){
    int j = 0;
    for (int i=0;i<numsSize;++i) {
        if(nums[i] != 0){
            nums[j] = nums[i];
            if(j != i) nums[i] = 0;
            j++;
        }   
    }
}

// Method 2 (92.94,22.13)

void moveZeroes(int* nums, int numsSize){
    int next = 0;
    for (int i = 0;i < numsSize;i++) {
        if(nums[i]!=0){
            nums[next++]=nums[i];
        }
    }
    for (int i = next;i < numsSize;i++) {
        nums[i] = 0;
    }
}

// Method 3 (92.94,22.13)

void swap(int *a, int *b) {
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

void moveZeroes(int* nums, int numsSize){
    for (int i=0, next=0; i<numsSize; i++) {
        if (nums[i] != 0) {
            swap(&nums[i],&nums[next++]);
        }
    }
}