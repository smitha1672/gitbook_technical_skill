# STL ALGORITHMS
## PROVINCE OF HEAPS
### make_heap
### push_heap
### pop_heap
## SHORE OF SORTING
### sort
### partial_sort
### nth_element
+ first n smallest numbers

```text
#include <algorithms>
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
    {
        cout << v[i] << " ";
    }
    return 0;
}

```

### sort_heap
### inplace_merge
