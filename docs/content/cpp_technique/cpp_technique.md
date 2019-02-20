#
## C++

## String

+ C++ printf with std::string?

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
