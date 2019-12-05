# STL ALGORITHMS
## PROVINCE OF HEAPS
### make_heap
### push_heap
### pop_heap
## SHORE OF SORTING
### sort

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
### inplace_merge
