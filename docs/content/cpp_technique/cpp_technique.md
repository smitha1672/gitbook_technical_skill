#
## C++

[GeeksforGeeks](https://www.geeksforgeeks.org/c-plus-plus/)

## [algorithms library in C++ STL](https://www.geeksforgeeks.org/algorithms-library-c-stl/)

+ [std::reverse() in C++](https://www.geeksforgeeks.org/stdreverse-in-c/)

```text
// CPP program to illustrate
// std::reverse() function of STL
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    vector <int> v ;
    // Inserting elements in vector
    for (int i = 0; i < 8; i++)
        v.push_back(i+10);
    cout << "Reverse only from index 5 to 7 in array:\n";
    // Reversing elements from index 5 to index 7
    reverse(v.begin() + 5, v.begin() + 8);
    // Displaying elements of vector
    vector <int> :: iterator it;
    for (it = v.begin(); it != v.end(); it++)
        cout << (*it) << " ";
    // Reversing directly from beginning to end
    cout << "\nReverse full array:\n";
    int a[] = {4, 5, 6, 7};
    std::reverse(std::begin(a), std::end(a));
    // Print the array
    std::cout << a[0] << a[1] << a[2] << a[3] << '\n';
    return 0;
}
```

## String

+ copy std::string into std::vector<char>

```text
std::vector has a constructor that takes two iterators. You can use that:

std::string str = "hello";
std::vector<char> data(str.begin(), str.end());
If you already have a vector and want to add the characters at the end, you need a back inserter:

std::string str = "hello";
std::vector<char> data = /* ... */;
std::copy(str.begin(), str.end(), std::back_inserter(data));
```

+ print string with printf and vector

```text
std::vector<char> vec;
vec.push_back('t');
vec.push_back('e');
vec.push_back('s');
vec.push_back('t');
vec.push_back('\0');
std::ostringstream vts;
if (!vec.empty()) {
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<char>(vts));
    // Now add the last element with no
    // delimiter
    vts << vec.back();
}
std::string s = vts.str();
printf("%s\n", s.c_str());
```

+ printf with std::string?

```c
#include <iostream>
#include <string>
#include <stdio.h>

int main()
{
    using namespace std;

    string myString = "Press ENTER to quit program!";
    cout << "Come up and C++ me some time." << endl;
    printf("Follow this command: %s", myString.c_str()); //note the use of c_str
    cin.get();

    return 0;
}
```

+ string::copy

```c
// string::copy
#include <iostream>
#include <string>

int main ()
{
    char buffer[20];
    std::string str ("Test string...");
    std::size_t length = str.copy(buffer,6,5);
    buffer[length]='\0';
    std::cout << "buffer contains: " << buffer << '\n';
    return 0;
}
```


```text
g++ -std=c++11 main.cpp
```

```text
reinterpret_cast
auto event
static_cast<uint32_t>
```
