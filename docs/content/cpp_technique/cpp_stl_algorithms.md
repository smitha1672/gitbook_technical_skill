# STL ALGORITHMS

[C++ reference](https://en.cppreference.com/w/)

# HEAPS

`make_heap`, `push_heap`, `pop_heap`

The heap can be either Max Heap or Min Heap.

```text
vector<int>v1{4, 10, 3, 5, 1};

        4
      /   \
    10     3
   /  \
  5    1

std::make_heap(v1.begin(), v1.end());

Max-Heap v1: 10 5 3 4 1
          10
        /    \
       5      3
     /   \
    4     1

v1.push_back(6);
Input v1: 10 5 3 4 1 6

        10
       /  \
      5    3
     / \  /
    4  1  6

push_heap(v1.begin(), v1.end());

        10
       /   \
      5     6
     / \   /
    4   1 3

Outpu v1: 10 5 6 4 1 3

Input v1: 10 5 6 4 1 3
pop_heap(v1.begin(), v1.end());

         6
       /   \
      5     3
     / \   /
    4   1 10
Output v1: 6 5 3 4 1 10
```

MIN-HEAP: std::make_heap(v2.begin(), v2.end(), std::greater<int>())

```text
vector<int>v1{4, 10, 3, 5, 1};
std::make_heap(v2.begin(), v2.end(), std::greater<int>());

Min-Heap v1: 1 4 3 5 10
          1
        /    \
       4      3
     /   \
    5     10

Output v1 = {1, 4, 3, 5, 10}
```

# SORTING

`sort`, `partial_sort`, `nth_element`, `sort_heap` and `inplace_merge`

## sort

+ general using

```text
#include <algorithms>
#include <iostream>

using namespace std;

int main(void)
{
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr+n);

    cout << "\nArray after sorting using "
        "default sort is : \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    return 0;
}
```

+ descending order

```text
...
sort(arr, arr+n, greater<int>());
...
```

### partial_sort

todo

### nth_element

+ first n smallest numbers

```text
#include <algorithms>
#include <iostream>
using namespace std;

int main(void)
{
    int v[] = { 30, 20, 10, 40, 60, 50, 70, 80 };

    // Using std::nth_element with n as 3
    std::nth_element(v, v + 2, v + 8);

    // Since, n is 3 so now first three numbers will be the
    // three smallest numbers in the whole array
    // Displaying first three smallest number
    for (i = 0; i < 3; ++i)
        cout << v[i] << " ";
    return 0;
}
```

+ first n largest numbers

```text
#include <algorithms>
#include <iostream>
using namespace std;

int main(void)
{
    int v[] = { 30, 20, 50, 60, 70, 10, 80, 40 }, i;

    // Using std::nth_element with n as 2
    std::nth_element(v, v + 1, v + 8, std::greater<int>());

    // Since, n is 2 so first 2 elements will be the largest
    // among all the array elements
    // Displaying First 2 elements
    for (i = 0; i < 2; ++i)
        cout << v[i] << " ";
    return 0;
}
```

### sort_heap

todo

### inplace_merge

Complexity: O(N log N)

inplace_merge(beg1, beg2, end) :
This function is used to sort two consecutively placed sorted ranges in a single container.
It takes 3 arguments, iterator to beginning of 1st sorted range,
iterator to beginning of 2nd sorted range, and iterator to last position.

```text
/*Leetcode #88 Merge Sorted Array*/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    copy(nums2.begin(), nums2.end(), nums1.begin()+m);
    inplace_merge(nums1.begin(), nums1.begin()+m, nums1.end());
}

int main()
{
    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;
    merge(nums1, m, nums2, n);
    for(const int &num:nums1)
        cout << num << " ";
    cout << "\n";
    return 0;
}

Output:
1 2 2 3 5 6
```

