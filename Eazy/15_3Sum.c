    // Method 1(Failed, give up, Cannot handle repeated array)

    bool check(int **arr, int a, int b, int c, int size){
        for (int i = 0; i < size; i++){
            int cnt = 0;
            for (int j = 0; j < 3; j++) {
                /*
                printf("%d, %d, %d\n", arr[i][0], arr[i][1], arr[i][2]);
                printf("a:%d, b:%d, c:%d\n", a, b, c);
                */
                if (arr[i][j] == a) {
                    cnt++;
                    a = -2147483647;
                }else if (arr[i][j] == b) {
                    cnt++;
                    b = -2147483647;
                }else if (arr[i][j] == c) {
                    cnt++;
                    c = -2147483647;
                }
            }
            // printf("%d\n",cnt);
            if( cnt >= 3 ) return false;
        }
        return true;
    }

    int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
        int **returnArr = (int **) calloc(1, sizeof(int *)), n=0;
        *returnColumnSizes = (int *) calloc(1, sizeof(int));
        for (int i = 0; i < numsSize; i++) {
            for (int j = i + 1; j < numsSize; j++) {
                for (int k = j + 1; k < numsSize; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0 ) {
                        if (check(returnArr, nums[i], nums[j], nums[k], n)) {
                            // printf("%d, %d, %d\n", nums[i], nums[j], nums[k]);
                            returnArr = (int **) realloc(returnArr, sizeof(int *)*(n+1)) ;
                            *returnColumnSizes = (int *) realloc(*returnColumnSizes, sizeof(int)*(n+1));
                            returnArr[n] = (int *) calloc(3, sizeof(int));
                            returnArr[n][0] = nums[i];
                            returnArr[n][1] = nums[j];
                            returnArr[n][2] = nums[k];
                            (*returnColumnSizes)[n++] = 3;
                        }
                    }
                }
            }
        }
        *returnSize = n;
        return returnArr;
    }


// Method 2(Failed, Time limitation)


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void *a, const void *b){
    return *(int *) a > *(int *) b;

}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort(nums, numsSize, sizeof(int), compare);
    int **returnArr = (int **) calloc(1, sizeof(int *)), n = 0;
    *returnColumnSizes = (int *) calloc(1, sizeof(int));
    for (int i = 0; i < numsSize-2; i++) {
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int j = i + 1, k = numsSize-1;
        while(j<k){
            int s=nums[k] + nums[i] + nums[j];
            if(s < 0){
                j++;
                while(j < k && nums[j] == nums[j - 1]) j++;
            }else if(s > 0){
                k--;
                while(j < k && nums[k] == nums[k + 1]) k--;
            }
            else{
                    returnArr = (int **) realloc(returnArr, sizeof(int *)*(n+1)) ;
                    *returnColumnSizes = (int *) realloc(*returnColumnSizes, sizeof(int)*(n+1));
                    returnArr[n] = (int *) calloc(3, sizeof(int));
                    returnArr[n][0] = nums[i];
                    returnArr[n][1] = nums[j];
                    returnArr[n][2] = nums[k];
                    (*returnColumnSizes)[n++] = 3;
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j - 1]) j++;
                    while(j < k && nums[k] == nums[k + 1]) k--;
            }
        }
    }
    *returnSize = n;
    return returnArr;
}