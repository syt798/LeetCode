/*
1、循环
2、二分
*/

int search(int* nums, int numsSize, int target){
    int ret = -1;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == target) {
            ret = i;
            break;
        }
    }
    
    return ret;
}
