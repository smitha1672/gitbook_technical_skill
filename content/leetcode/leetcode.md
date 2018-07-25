## [189. RotateArray](https://leetcode.com/problems/rotate-array/description/)
<!--- limiation line
<br>---------------20------------------40-----------------60------------------80--------------
-->
```text
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

Note:
Try to come up as many solutions as you can, there are at least 3 different ways
to solve this problem.
Could you do it in-place with O(1) extra space?
```

<br>**Answer**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int *array, int arraySize, int idx)
{
  int i = 0;

  printf("%d:", idx);
  for (i = 0; i < arraySize; i++) {
    printf(" %d", array[i]);
  }
  printf("\n");
}

void rotate(int* nums, int numsSize, int k)
{
  int i = 0, j = k;
  int up = 0;

  for (j = 0; j < k; j++) {
    up = nums[numsSize-1];
    for (i = (numsSize-1); i > 0; i--) {
      nums[i] = nums[i-1];
    }
    nums[0] = up;
  }
}

void main(void)
{
  int nums[] = {1,2,3,4,5,6,7};
  int nums_size = sizeof(nums)/sizeof(int);

  printArray(nums, nums_size, 100);
  rotate(nums, nums_size, 6);
  printArray(nums, nums_size, 101);
}
```
## [27. RemoveElement](https://leetcode.com/problems/remove-element/description/)
<!--- limiation line
<br>---------------20------------------40-----------------60------------------80--------------
-->
Question
```text
Given an array nums and a value val, remove all instances of that value in-place and return
the new length.

Do not allocate extra space for another array, you must do this by modifying the input array
in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the
new length.

Example 1:
Given nums = [3,2,2,3], val = 3,
Your function should return length = 2, with the first two elements of nums being 2.
It doesn't matter what you leave beyond the returned length.

Example 2:
Given nums = [0,1,2,2,3,0,4,2], val = 2,
Your function should return length = 5, with the first five elements of
nums containing 0, 1, 3, 0, and 4.
Note that the order of those five elements can be arbitrary.
It doesn't matter what values are set beyond the returned length.
Clarification:
Confused why the returned value is an integer but your answer is an array?
Note that the input array is passed in by reference, which means modification to the input
array will be known to the caller as well.

Internally you can think of this:
// nums is passed in by reference. (i.e., without making a copy)
int len = removeElement(nums, val);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
      print(nums[i]);
}
```
<br>**Answer**
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void xorSwap (int *x, int *y) {
  if (x != y) {
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
  }
}

void printElement(int *nums, int numsSize, int idx)
{
  for (int i = 0; i < numsSize; i++)
    printf("%d: nums[%d] = %d\n", idx, i, *(nums+i));
  printf("end \n\n");
}

int removeElement(int* nums, int numsSize, int val)
{
  int i = 0;
  for (int j = 0; j < numsSize; j++) {
    if (nums[j] != val) {
      nums[i] = nums[j];
      i++;
    }
  }
  return i;
}

void main (void)
{
  int nums[] = {3, 2, 2, 3};
  int i = 0;
  int length = 0;

  for (i = 0; i < sizeof(nums)/sizeof(int); i++)
    printf("nums_org[%d] = %d\n",
           i, nums[i]);

  length = removeElement(nums, sizeof(nums)/sizeof(int), 2);
  if (length)
    printf("length = %d\n", length);

  printf("\n\n");
  for (i = 0; i < sizeof(nums)/sizeof(int); i++)
    printf("nums_new[%d] = %d\n",
           i, nums[i]);
}
```
