#
## Leetcode
## [8. String to Integer atoi](https://leetcode.com/problems/string-to-integer-atoi/description/)
<!--- limiation line
<br>---------------20------------------40-----------------60------------------80--------------
-->

Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first
non-whitespace character is found. Then, starting from this character, takes an optional
initial plus or minus sign followed by as many numerical digits as possible, and interprets
them as a numerical value.

The string can contain additional characters after those that form the integral number,
which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number,
or if no such sequence exists because either str is empty or it contains only whitespace
characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:
Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit
signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of
representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.

Example 1:
Input: "42"
Output: 42

Example 2:
Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
Then take as many numerical digits as possible, which gets 42.

Example 3:
Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical
digit.

Example 4:
Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical
digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit
signed integer. Thefore INT_MIN (−231) is returned.

<br>**Answer**
```c
int
myAtoi(char* str)
{
    long result = 0;
    int sign = 1;
    //discard the first sequence of whitespace characters.
    while (isspace(*str))
        str++;
    if ((*str == '+') || (*str == '-')) {
        sign = (*str == '+') ? 1:0;
        str++;
    }
    if (!isdigit(*str))
        return result;
    while (isdigit(*str) && (result <= INT_MAX)) {
        result = result * 10 + *str - '0' + 0;
        str++;
    }
    if (result > INT_MAX)
        return ((sign == 1) ? INT_MAX : INT_MIN);
    return ((sign == 1)? result : -result);
}

void
main (void)
{
    char input[12] = "1534236469";
    int output = 0;
    printf("input: %s\n", input);
    output = myAtoi(input);
    printf("out: %d\n", output);
}
```
## [88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)
<!--- limiation line
<br>---------------20------------------40-----------------60------------------80--------------
-->

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold
additional elements from nums2.

Example:
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
Output: [1,2,2,3,5,6]

<br>**Answer**
```c
void merge(int* nums1, int m, int* nums2, int n)
{
  int *numsTemp = (int*)malloc(sizeof(int)*(m+n));
  int i = 0, j = 0, k = 0;

  for (; (i < m) && (j < n); k++)
    numsTemp[k] = ((nums1[i] <= nums2[j])? nums1[i++]:nums2[j++]);
  for(; i < m; )
    numsTemp[k++] = nums1[i++];
  for (; j < n; )
    numsTemp[k++] = nums2[j++];
  memcpy(nums1, numsTemp, (sizeof(int)*(m+n)));
  free(numsTemp);
}

void main(void)
{
  int *nums1 = NULL, *nums2 = NULL;
  const int nums1Size = 3, nums2Size = 5;
  int initial = 0;

  nums1 = (int*)malloc(sizeof(int)*(nums1Size+nums2Size));
  nums2 = (int*)malloc(sizeof(int)*nums2Size);

  initial = 2;
  for (int i = 0; i < nums1Size; i++)
    nums1[i] = (initial*=2);

  initial = 3;
  for (int i = 0; i < nums2Size; i++)
    nums2[i] = (initial*=3);

  merge(nums1, nums1Size, nums2, nums2Size);
  free(nums1);
  free(nums2);
}
```
## [541. Reverse String II](https://leetcode.com/problems/reverse-string-ii/)
<!--- limiation line
<br>---------------20------------------40-----------------60------------------80--------------
-->

Given a string and an integer k, you need to reverse the first k characters for every 2k
characters counting from the start of the string. If there are less than k characters left,
reverse all of them. If there are less than 2k but greater than or equal to k characters,
then reverse the first k characters and left the other as original.

Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]

<br>**Answer**
```c
void
reverse(int start, int end, char* s)
{
    char tmp;
    while (start < end) {
        tmp = s[end];
        s[end--] = s[start];
        s[start++] = tmp;
    }
}

char*
reverseStr(char* s, int k)
{
    size_t len = strlen(s);
    if (len <= k) {
        reverse(0, len-1, s);
        return s;
    }
    for (int i = 0; i < len; i += (2*k)) {
        if (i+(2*k) <= len)   /*at least 2k left*/
            reverse(i, i+k-1, s);
        else if ((len-i) >= k) { /*more than or equal to k left*/
            reverse(i, i+k-1, s);
            break;
        } else if ((len-i) < k) { /*less than k,reverse i to len-1*/
            reverse(i, i+k-1, s);
            break;
        }
    }
    return s;
}

#define ITEM 10000
void
main(void)
{
    char s[] = "abcdefg";
    int k = 2;
    char* t = NULL;
    reverseStr(s, k);
    printf("s: %s\n", s);
}
```
## [7. Reverse Integer](https://leetcode.com/problems/reverse-integer/)
<!--- limiation line
<br>---------------20------------------40-----------------60------------------80--------------
-->
```text
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:
Input: 123
Output: 321

Example 2:
Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit
signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your
function returns 0 when the reversed integer overflows.
```

<br>**Answer**
```c
#include <stdio.h>
#include <limits.h>

int reverse(int x)
{
  long long val = 0;

  do
  {
    val = val * 10 + x % 10;
    x /= 10;
  } while (x);

  return (val > INT_MAX || val < INT_MIN) ? 0 : val;
}

void main (void)
{
  int input = -2147483648;
  int output = 0;

  printf("input: %d\n", input);
  output = reverse(input);
  printf("out: %d\n", output);
}
```
## [344. Reverse String](https://leetcode.com/problems/reverse-string/description/)
<!--- limiation line
<br>---------------20------------------40-----------------60------------------80--------------
-->
```text
Write a function that takes a string as input and returns the string reversed.

Example 1:
Input: "hello"
Output: "olleh"

Example 2:
Input: "A man, a plan, a canal: Panama"
Output: "amanaP :lanac a ,nalp a ,nam A"
```

<br>**Answer**
```c
#include <stdio.h>
#include <string.h>

void charXorSwap(char *x, char *y)
{
  if (x != y) {
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
  }
}

char* reverseString(char* s) {
  size_t len = strlen(s)-1;
  int j = 0, k = 0;

  k = len;
  while (j < k)
    charXorSwap(&s[j++], &s[k--]);
  return s;
}

void main(void)
{
  char s[40] = "";

  reverseString(s);
  printf("%s\n", s);
}
```
## [283. Move Zeroes](https://leetcode.com/problems/move-zeroes/description/)
<!--- limiation line
<br>---------------20------------------40-----------------60------------------80--------------
-->

Given an array nums, write a function to move all 0's to the end of it while maintaining the
relative order of the non-zero elements

For example, given nums = [0, 1, 0, 3, 12], after calling your function,
nums should be [1, 3, 12, 0, 0].

Note:
  1. You must do this in-place without making a copy of the array.
  2. Minimize the total number of operations.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

<br>**Answer**
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void moveZeroes(int* nums, int numsSize)
{
  int i  = 0;
  int *new_nums = (int*)malloc(numsSize*sizeof(int));
  int *ptrNewNums = NULL;
  int front = 0, end = (numsSize - 1);
  if (new_nums)
    ptrNewNums = new_nums;
  for (i = 0; i < numsSize; i++) {
    if (nums[i] != 0) {
      *(ptrNewNums + (front++)) = nums[i];
    } else if (nums[i] == 0) {
      *(ptrNewNums + (end--)) = 0;
    }
  }
  memcpy(nums, new_nums, (numsSize*sizeof(int)));
  free(new_nums);
}

void main (void)
{
  int nums[] = {0, 2, 3, 0, 5, 0, 7, 8, 0};
  int i = 0;
  for (i = 0; i < sizeof(nums)/sizeof(int); i++)
    printf("nums_org[%d] = %d\n",
           i, nums[i]);
  moveZeroes(nums, (sizeof(nums)/sizeof(int)));
  printf("\n\n");
  for (i = 0; i < sizeof(nums)/sizeof(int); i++)
    printf("nums_new[%d] = %d\n",
           i, nums[i]);
}
```

## [189. RotateArray](https://leetcode.com/problems/rotate-array/description/)
<!--- limiation line
<br>---------------20------------------40-----------------60------------------80--------------
-->

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
