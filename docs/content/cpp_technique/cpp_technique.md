# C ++

```text
g++ -std=c++11 main.cpp
```

<br/>
[thispointer.com](https://thispointer.com/c-interview-questions/)
<br/>
[GeeksforGeeks](https://www.geeksforgeeks.org/c-plus-plus/)
<br/>
[All C++ Answers](https://www.codegrepper.com/code-examples/cpp)

## TODO

## [INHERITANCE](https://www.geeksforgeeks.org/inheritance-in-c/)

Modes of Inheritance

```text
1. Public mode
2. Protected mode
3. Private mode
```

Implementing inheritance Syntax

```text
class subclass_name : access_mode base_class_name
{
      //body of subclass
};
```

Types of Inheritance

```text
1. Single Inheritance
2. Multiple Inheritance
3. Multilevel Inheritance
4. Hierarchical Inheritance
5. Hybrid (Virtual) Inheritance
```

### [ACCESS MODIFIERS Public/Private/Protected](https://www.geeksforgeeks.org/access-modifiers-in-c/#:~:targetText=Protected%3A%20Protected%20access%20modifier%20is,derived%20class)%20of%20that%20class.)

To expalin Public/Private/Protected

## [OVERLOADING](https://www.geeksforgeeks.org/operator-overloading-c/)

Following is the list of operators that cannot be overloaded.

```text
. (dot)
::
?:
sizeof
```

### simple example

```text
#include<iostream>
using namespace std;

class Complex {
    private:
        int real, imag;
    public:
        Complex(int r = 0, int i =0) {real = r; imag = i;}

        // This is automatically called when '+' is used with
        // between two Complex objects
        Complex operator + (Complex const &obj) {
            Complex res;
            res.real = real + obj.real;
            res.imag = imag + obj.imag;
            return res;
        }
        void print() { cout << real
            << " + i" << imag << endl; }
};

int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2; // An example call to "operator+"
    c3.print();
}
```

### [types of operator overloading](https://www.geeksforgeeks.org/types-of-operator-overloading-in-c/)

Operator Overloading can be done by using three approaches, they are:

1. Overloading unary operator.
2. Overloading binary operator.
3. Overloading binary operator using a `friend` function.

+ issue learning

```text
class Box {
private:
    ...
public:
    bool operator<(Box&);                       //Overloading binary operator
    friend ostream& operator<<(ostream&, Box&); // Overloading binary operator using a friend function
};

bool Box::operator<(Box& B)
{
    return false;
}

ostream& Box::operator<<(ostream& out, Box& box) // building failure
ostream& operator<<(ostream& out, Box& box) // building pass
{
    return out;
}
```


## [ITERATORS](https://www.geeksforgeeks.org/iterators-c-stl/)

### vector

```text
vector<int> ar = { 1, 2, 3, 4, 5 };
// Declaring iterator to a vector
vector<int>::iterator ptr;

// Displaying vector elements using begin() and end()
cout << "The vector elements are : ";
for (ptr = ar.begin(); ptr < ar.end(); ptr++)
    cout << *ptr << " ";
```

## [CONSTRUCTORS](https://www.geeksforgeeks.org/constructors-c/#:~:targetText=A%20constructor%20is%20a%20member,member%20function%20of%20the%20class.)

A constructor is a member function of a class which initializes objects of a class.
In C++, Constructor is automatically called when object(instance of class) create.
It is special member function of the class.

```text
1. Constructor has same name as the class itself
2. Constructors don’t have return type
3. A constructor is automatically called when an object is created.
4. If we do not specify a constructor, C++ compiler generates a default constructor for us
(expects no parameters and has an empty body).
```

```text
class Box {
public:
    int l, b, h;
public:
    Box();
    Box(int l, int b, int h);
};

/*
Default Constructors:
Default constructor is the constructor which doesn’t take any argument.
It has no parameters.
*/
Box::Box()
{
    l = b = h = 0;
}

/*
Parameterized Constructors:
It is possible to pass arguments to constructors.
Typically, these arguments help initialize an object when it is created.
To create a parameterized constructor, simply add parameters to it the way you would to any other
function.
When you define the constructor’s body, use the parameters to initialize the object.
*/
Box::Box(int il, int ib, int ih)
{
    l = il;
    b = ib;
    h = ih;
}

int main(void)
{
    Box box1(1, 2, 3);
    Box box2;
    std::cout << box1.l << " "<< box2.l << "\n";
    return 0;
}

output: 1 0
```

## CLASS

The data members of `a class are private by default` and `the members of a structure are public by default`.

It also has access specifiers, which restrict the access of member elements.
The primarily used ones are the following:
public: Public members (variables, methods) can be accessed from anywhere the code is visible.
private: Private members can be accessed only by other member functions, and it can not be accessed outside of class.

Class can be represented in the form of

```text
class ClassName {
access_specifier1:
    type1 val1;
    type2 val2;
    ret_type1 method1(type_arg1 arg1, type_arg2 arg2,...)
    ...
access_specifier2:
    type3 val3;
    type4 val4;
    ret_type2 method2(type_arg3 arg3, type_arg4 arg4,...)
    ...
};
```

it's a common practice to make all variables private, and set/get them using public methods. For example:

```text
class SampleClass {
    private:
        int val;
    public:
        void set(int a) {
            val = a;
        }
        int get() {
            return val;
        }
};
```

## [VECTOR](https://www.geeksforgeeks.org/vector-in-cpp-stl/)

[ref.1](http://larry850806.github.io/2016/06/06/STL2/)

### [initialize a vector with 5 different ways](https://www.geeksforgeeks.org/initialize-a-vector-in-cpp-different-ways/)

```text
int main(void)
{
    int n = 3;

    // Create a vector of size n with
    // all values as 10.
    vector<int> vect(n, 10);
    return 0;
}

int main (void)
{
    vector<int> vect {10, 20, 30};
    ...
    return 0;
}

int main (void)
{
    int arr[] = { 10, 20, 30 };
    int n = sizeof(arr) / sizeof(arr[0]);
    /*vect = 10, 20, 30*/
    vector<int> vect(arr, arr + n);
    ...
    return 0;
}

int main (void)
{
    int arr[] = { 10, 20, 30 };
    int n = sizeof(arr) / sizeof(arr[0]);
    /*vect = 10, 20, 30*/
    vector<int> vect(arr, arr + n);
    ...
    return 0;
}

int main (void)
{
    // Create an empty vector
    vector<int> vect;

    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(30);

    for (int x : vect)
        cout << x << " ";

    return 0;
}

```

### 2D vector

```text
# https://thispointer.com/creating-a-matrix-using-2d-vector-in-c-vector-of-vectors/

# Declaration of 2D vector or vector of vector in C++
std::vector <std::vector<int> > vec2D

# Initializing Vector of Vector – 2D vector

std::vector <NUMBER OF ELEMENTS, VALUE OF EACH ELEMENT>
std::vector<int> (4, 1)

# Now to create a vector of 5 vectors in which each vector is initialized as above, we will use following syntax,
std::vector <std::vector > vec2D(5, std::vector(4, 1));

Output

1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 ,

# Adding a new row in 2D vector
vec2D.push_back(std::vector<int>(4, 11));
```

```text
# https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/

// C++ code to demonstrate 2D vector
#include <iostream>
#include <vector> // for 2D vector
using namespace std;

int main()
{
    // Initializing 2D vector "vect" with
    // values
    vector<vector<int> > vect{ { 1, 2, 3 },
                               { 4, 5, 6 },
                               { 7, 8, 9 } };

    // Displaying the 2D vector
    for (int i = 0; i < vect.size(); i++) {
        for (int j = 0; j < vect[i].size(); j++)
            cout << vect[i][j] << " ";
        cout << endl;
    }

    return 0;
}

Outout :

1 2 3
4 5 6
7 8 9
```

### insert and erase

```text
int arr[] = {1, 2, 3, 4, 5};
vector<int> vec(arr, arr+5);    //vec = [1, 2, 3, 4, 5]
vec.insert(vec.begin(), 0); //vec = [0, 1, 2, 3, 4, 5]
vec.insert(vec.end(), 3, 100); //vec = [0, 1, 2, 3, 4, 5, 100, 100, 100]
vec.erase(vec.begin()); //vec = [1, 2, 3, 4, 5, 100, 100, 100]
vec.erase(vec.end()-1); //vec = [1, 2, 3, 4, 5, 100, 100]
vec.erase(vec.begin(), vec.begin() + 5); //vec = [100, 100];
cout << vec.size() << endl; //size = 2
```

## STRING

+ [C++ string class and its applications](https://www.geeksforgeeks.org/c-string-class-and-its-applications/)

```text
C++ string class has a lot of functions to handle string easily. Most useful of them are demonstrated in below code.
// C++ program to demonstrate various function string class
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // various constructor of string class
    // initialization by raw string
    string str1("first string");
    // initialization by another string
    string str2(str1);
    // initialization by character with number of occurence
    string str3(5, '#');
    // initialization by part of another string
    string str4(str1, 6, 6); // from 6th index (second parameter)
    // 6 characters (third parameter)
    // initialization by part of another string : iteartor version
    string str5(str2.begin(), str2.begin() + 5);
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    cout << str4 << endl;
    cout << str5 << endl;
    // assignment operator
    string str6 = str4;
    // clear function deletes all character from string
    str4.clear();
    // both size() and length() return length of string and
    // they work as synonyms
    int len = str6.length(); // Same as "len = str6.size();"
    cout << "Length of string is : " << len << endl;
    // a particular character can be accessed using at /
    // [] operator
    char ch = str6.at(2); // Same as "ch = str6[2];"
    cout << "third character of string is : " << ch << endl;
    // front return first character and back returns last charcter
    // of string
    char ch_f = str6.front(); // Same as "ch_f = str6[0];"
    char ch_b = str6.back(); // Same as below
    // "ch_b = str6[str6.length() - 1];"
    cout << "First char is : " << ch_f << ", Last char is : "
        << ch_b << endl;
    // c_str returns null terminated char array version of string
    const char* charstr = str6.c_str();
    printf("%s\n", charstr);
    // append add the argument string at the end
    str6.append(" extension");
    // same as str6 += " extension"
    // another version of append, which appends part of other
    // string
    str4.append(str6, 0, 6); // at 0th position 6 character
    cout << str6 << endl;
    cout << str4 << endl;
    // find returns index where pattern is found.
    // If pattern is not there it returns predefined
    // constant npos whose value is -1
    if (str6.find(str4) != string::npos)
        cout << "str4 found in str6 at " << str6.find(str4)
            << " pos" << endl;
    else
        cout << "str4 not found in str6" << endl;
    // substr(a, b) function returns a substring of b length
    // starting from index a
    cout << str6.substr(7, 3) << endl;
    // if second argument is not passed, string till end is
    // taken as substring
    cout << str6.substr(7) << endl;
    // erase(a, b) deletes b characters at index a
    str6.erase(7, 4);
    cout << str6 << endl;
    // iterator version of erase
    str6.erase(str6.begin() + 5, str6.end() - 3);
    cout << str6 << endl;
    str6 = "This is a examples";
    // replace(a, b, str) replaces b characters from a index by str
    str6.replace(2, 7, "ese are test");
    cout << str6 << endl;
    return 0;
}
```

```text
Output:
first string
first string
#####
string
first
Length of string is : 6
third character of string is : r
First char is : s, Last char is : g
string
string extension
string
str4 found in str6 at 0 pos
ext
extension
string nsion
strinion
These are test examples
```

```text
On basis of above string function some application are written below :
// C++ program to demonstrate uses of some string function
#include <bits/stdc++.h>
using namespace std;

// this function returns floating point part of a number-string
string
returnFloatingPart(string str)
{
    int pos = str.find(".");
    if (pos == string::npos)
        return "";
    else
        return str.substr(pos + 1);
}

// this function checks whether string contains all digit or not
bool
containsOnlyDigit(string str)
{
    int l = str.length();
    for (int i = 0; i < l; i++) {
        if (str.at(i) < '0' || str.at(i) > '9')
            return false;
    }
    // if we reach here all character are digits
    return true;
}

// this function replaces all single space by %20
// Used in URLS
string
replaceBlankWith20(string str)
{
    string replaceby = "%20";
    int n = 0;
    // loop till all space are replaced
    while ((n = str.find(" ", n)) != string::npos ) {
        str.replace(n, 1, replaceby);
        n += replaceby.length();
    }
    return str;
}

// driver function to check above methods
int
main()
{
    string fnum = "23.342";
    cout << "Floating part is : " << returnFloatingPart(fnum)
        << endl;
    string num = "3452";
    if (containsOnlyDigit(num))
        cout << "string contains only digit" << endl;
    string urlex = "google com in";
    cout << replaceBlankWith20(urlex) << endl;
    return 0;
}
```

```text
Output
Floating part is : 342
string contains only digit
google%20com%20in
```

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

## STRINGSTREAM

```text
clear() — to clear the stream
str() — to get and set string object whose content is present in stream.
operator << — add a string to the stringstream object.
operator >> — read something from the stringstream object,
```

### example

+ [to count frequencies of words](https://www.geeksforgeeks.org/stringstream-c-applications/)

```text
#include <bits/stdc++.h>

using namespace std;

void printFrequency(string st)
{
    // each word it mapped to it's frequency
    map<string, int> FW;
    stringstream ss(st); // Used for breaking words
    string Word; // To store individual words

    while (ss >> Word)
        FW[Word]++;

    map<string, int>::iterator m;
    for (m = FW.begin(); m != FW.end(); m++)
        cout << m->first << " -> "
            << m->second << "\n";
}

int main(void)
{
    string s = "Geeks For Geeks Ide"
    printFrequency(s);
    return 0;
}
```

## [RANGE-BASED](https://www.geeksforgeeks.org/range-based-loop-c/)

```text
for ( range_declaration : range_expression )
    loop_statement

Parameters :
range_declaration :
a declaration of a named variable, whose type is the
type of the element of the sequence represented by
range_expression, or a reference to that type.
Often uses the auto specifier for automatic type
deduction.

range_expression :
any expression that represents a suitable sequence
or a braced-init-list.

loop_statement :
any statement, typically a compound statement, which
is the body of the loop.
```

```text
// Illustration of range-for loop
// using CPP code
#include <iostream>
#include <vector>
#include <map>

//Driver
int
main()
{
    // Iterating over whole array
    std::vector<int> v = {0, 1, 2, 3, 4, 5};
    for (auto i : v)
        std::cout << i << ' ';
    std::cout << '\n';
    // the initializer may be a braced-init-list
    for (int n : {0, 1, 2, 3, 4, 5})
        std::cout << n << ' ';
    std::cout << '\n';
    // Iterating over array
    int a[] = {0, 1, 2, 3, 4, 5};
    for (int n : a)
        std::cout << n << ' ';
    std::cout << '\n';
    // Just running a loop for every array
    // element
    for (int n : a)
        std::cout << "In loop" << ' ';
    std::cout << '\n';
    // Printing string characters
    std::string str = "Geeks";
    for (char c : str)
        std::cout << c << ' ';
    std::cout << '\n';
    // Printing keys and values of a map
    std::map <int, int> MAP({{1, 1}, {2, 2}, {3, 3}});
    for (auto i : MAP)
        std::cout << '{' << i.first << ", " << i.second << "}\n";
}
```

```text
Output:
0 1 2 3 4 5
0 1 2 3 4 5
0 1 2 3 4 5
In loop In loop In loop In loop In loop In loop
G e e k s
{1, 1}
{2, 2}
{3, 3}
```

## [MAP](https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/)
### upper bound

```text
returns an iterator to the first element greater than the given key
Syntax:
    map_name.upper_bound(key)
```

```text
#include <map>

int main()
{
    using namespace std;
    // initialize container
    map<int, int> mp;

    // insert elements in random order
    mp.insert({ 12, 30 });
    mp.insert({ 11, 10 });
    mp.insert({ 15, 50 });
    mp.insert({ 14, 40 });

    // when 11 is present
    auto it = mp.upper_bound(11);
    cout << "The upper bound of key 11 is ";
    cout << (*it).first << " " << (*it).second << endl;

    // when 13 is not present
    it = mp.upper_bound(13);
    cout << "The upper bound of key 13 is ";
    cout << (*it).first << " " << (*it).second << endl;

    // when 17 is exceeds the maximum key, so size
    // of mp is returned as key and value as 0.
    it = mp.upper_bound(17);
    cout << "The upper bound of key 17 is ";
    cout << (*it).first << " " << (*it).second;
    return 0;
}

After map:
11 10
12 30 < key:11 upper bound
14 40 < key:13 upper bound
15 50
-- -- < key:17 upper bound

Output:
The upper bound of key 11 is 12 30
The upper bound of key 13 is 14 40
The upper bound of key 17 is 4 0
```

### lower bound

```text
Returns an iterator pointing to the first element that is not less than
 (i.e. greater or equal to) key.
Syntax:
    map_name.lower_bound(key)
```

```text
// C++ function for illustration
// map::lower_bound() function
#include <map>

int main()
{
    using namespace std;

    // initialize container
    map<int, int> mp;

    // insert elements in random order
    mp.insert({ 2, 30 });
    mp.insert({ 1, 10 });
    mp.insert({ 5, 50 });
    mp.insert({ 4, 40 });
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << (*it).first << " " << (*it).second << endl;
    }

    // when 2 is present
    auto it = mp.lower_bound(2);
    cout << "The lower bound of key 2 is ";
    cout << (*it).first << " " << (*it).second << endl;

    // when 3 is not present
    // points to next greater after 3
    it = mp.lower_bound(3);
    cout << "The lower bound of key 3 is ";
    cout << (*it).first << " " << (*it).second;

    // when 6 exceeds
    it = mp.lower_bound(6);
    cout << "\nThe lower bound of key 6 is ";
    cout << (*it).first << " " << (*it).second;
    return 0;
}

Output:
1 10
2 30 < key:2 lower bound
4 40 < key:3 lower bound
5 50
- -- < key:6 lower bound
The lower bound of key 2 is 2 30
The lower bound of key 3 is 4 40
The lower bound of key 6 is 4 0
```

### [map vs unordered_map](https://www.geeksforgeeks.org/map-vs-unordered_map-c/)

| Title | map | unordered_map |
| ----- | --- | ------------  |
|Ordering|increasing order(By Default)|no ordering|
|Implementation|Self balancing BST(Like Red-Black Tree)|Hash Table|
|Search Time|log(n)|O(1) Average/O(n) Worst Case|
|Insertion Time|log(n) + Rebalance|Same as search|
|Deletion time|log(n) + Rebalance|Same as search|

+ Use std::map when

<img src="https://1.bp.blogspot.com/-irj_g2Xr7E8/VmU8mlBPOVI/AAAAAAAA_K4/sIdTgAMLUxE/s1600/27.4.png"
width="70%"
height="70%"
alt="map key and value"
align=center />

<img src="https://3.bp.blogspot.com/-p2D7ql_iuFE/VmU7pe7zQrI/AAAAAAAA_Ks/WC3G3ADrKBE/s1600/27.7.png"
width="70%"
height="70%"
alt="map iterator"
align=center />

```text
# You need ordered data.
# You would have to print/access the data (in sorted order).
# You need predecessor/successor of elements.
# See advantages of BST over Hash Table for more cases.
```

```text
#include <map>
int main()
{
    // Ordered map
    std::map<int, int> order;

    // Mapping values to keys
    order[5] = 10;
    order[3] = 5;
    order[20] = 100;
    order[1] = 1;

    // Iterating the map and printing ordered values
    for (auto i = order.begin(); i != order.end(); i++) {
        std::cout << i->first << " : " << i->second << '\n';
    }
}

Output:
1 : 1
3 : 5
5 : 10
20 : 100
```

+ Use std::unordered_map when

```text
# You need to keep count of some data (Example – strings) and no ordering is required.
# You need single element access i.e. no traversal.
```

```text
#include <unordered_map>
int main()
{
    // Unordered map
    std::unordered_map<int, int> order;

    // Mapping values to keys
    order[5] = 10;
    order[3] = 5;
    order[20] = 100;
    order[1] = 1;

    // Iterating the map and printing unordered values
    for (auto i = order.begin(); i != order.end(); i++) {
        std::cout << i->first << " : " << i->second << '\n';
    }
}

Output :
1 : 1
3 : 5
20 : 100
5 : 10
```
## ALGORITHMS
### [array sum](https://www.geeksforgeeks.org/array-sum-in-cpp-stl/)

```text
In C++, we can quickly find array sum using accumulate()

#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

// User defined function that returns sum of
// arr[] using accumulate() library function.
int
arraySum(int a[], int n)
{
    int initial_sum = 0;
    return accumulate(a, a+n, initial_sum);
}

int
main()
{
    int a[] = {5, 10, 15} ;
    int n = sizeof(a)/sizeof(a[0]);
    cout << arraySum(a, n) << endl; // output: 30
    return 0;
}

//or

// User defined function that returns sum of
// arr[] using accumulate() library function.
int
arraySum(vector<int>& v)
{
    int initial_sum = 0;
    return accumulate(v.begin(), v.end(), initial_sum);
}

int
main()
{
    vector<int> v;
    v.push_back(5);
    v.push_back(10);
    v.push_back(15);
    cout << arraySum(v) << endl;
    return 0;
}
```

### [to find the maximum element](https://www.geeksforgeeks.org/how-to-find-the-maximum-element-of-a-vector-using-stl-in-c/)

```text
#include <vector>
#include <algorithm>
#include <iostream>

int
example_1(void)
{
    using namespace std;
    // Get the vector
    int arr[] = { 1, 45, 54, 71, 76, 12 };
    vector<int> a(arr, arr+(sizeof(arr)/sizeof(arr[0])));
    // Print the vector
    cout << "Example1 Vector: ";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
    // Find the max element
    cout << "\nMax Element = "
        << *max_element(a.begin(), a.end()) << endl; // Output: 76
    return 0;
}

int
example_2(void)
{
    // Get the vector
    int arr[] = { 1, 45, 54, 71, 76, 12 };
    std::vector<int> a(arr, arr+(sizeof(arr)/sizeof(arr[0])));
    // Print the vector
    std::cout << "Eample2 Vector: ";
    for (int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    // Find the max element
    std::cout << "\nMax Element = "
        << *std::max_element(a.begin(), a.end()) << std::endl; // Output: 76
    return 0;
}

int
example_3(void)
{
    using namespace std;
    int v[] = { 'a', 'c', 'k', 'd', 'e', 'f', 'h' };
    // Finding the maximum value between the first and the
    // fourth element
    int* i1;
    i1 = std::max_element(v, v + 4);
    cout << char(*i1) << "\n"; // output: k
    return 0;
}
```

### 105 STL Algorithms

+ rotate

```text
1. left Rotation : To rotate left, we need to add the vector index. For example, you have to rotate
vector left 3 times. The 3th index of vector becomes first element. vec.begin() + 3 will rotate
vector 3 times left.

2. Right Rotation : To rotate right, we need to subtract the vector index. For example, you have to
rotate vector right 3 times. The 3th last index of vector becomes first element.
vec.begin()+vec.size()-3 will rotate vector 3 times right.
```

```text
#include <algorithm>

int main(void)
{
    ...
    // Rotate vector left 3 times.
    int rotL=3;
    // std::rotate function
    std::rotate(vec1.begin(), vec1.begin()+rotL, vec1.end());

    // Rotate vector right 4 times.
    int rotR = 4;
    // std::rotate function
    std::rotate(vec2.begin(), vec2.begin()+vec2.size()-rotR, vec2.end());
    return 0;
}

```

+ [reverse](https://www.geeksforgeeks.org/stdreverse-in-c/)

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

## SKILL

### cout float point

```text
#include <iomanip>      // std::setprecision
using namespace std;

int main (void)
{
    double pi = 3.14159, npi = -3.14159;
    cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
    cout << fixed << setprecision(1) << pi <<" "<<npi<<endl;
    cout << fixed << setprecision(2) << pi <<" "<<npi<<endl;
    cout << fixed << setprecision(3) << pi <<" "<<npi<<endl;
    cout << fixed << setprecision(4) << pi <<" "<<npi<<endl;
    cout << fixed << setprecision(5) << pi <<" "<<npi<<endl;
    cout << fixed << setprecision(6) << pi <<" "<<npi<<endl;
    return 0;
}
```

Output

```text
3 -3
3.1 -3.1
3.14 -3.14
3.142 -3.142
3.1416 -3.1416
3.14159 -3.14159
3.141590 -3.141590
```

## [std::`back_inserter`](https://www.geeksforgeeks.org/stdback_inserter-in-cpp/)

`std::back_inserter` constructs a back-insert iterator that inserts new elements at the end of the container to which it is applied. It is defined inside the header file.

+ Example 1

```text
// C++ program to demonstrate std::back_inserter
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    // Declaring first container
    vector<int> v1 = { 1, 2, 3 };

    // Declaring second container for
    // copying values
    vector<int> v2 = { 4, 5, 6 };

    // Using std::back_inserter inside std::copy
    std::copy(v1.begin(), v1.end(), std::back_inserter(v2));
    // v2 now contains 4 5 6 1 2 3

    // Displaying v1 and v2
    cout << "v1 = ";

    int i;
    for (i = 0; i < 3; ++i) {
        cout << v1[i] << " ";
    }

    cout << "\nv2 = ";
    for (i = 0; i < 6; ++i) {
        cout << v2[i] << " ";
    }

    return 0;
}

Output:

v1 = 1 2 3
v2 = 4 5 6 1 2 3
```

+ Example 2

No prior Knowledge of size of container required : One of the scenario where such a function can be extremely helpful is when we don’t know the size of the container,
i.e., how many elements will be inserted into it, so one way is to make that container of extremely large size,
but the most efficient way will be to use `std::back_inserter()` in such a case, without declaring the size of the container.

```text
// C++ program to demonstrate std::back_inserter
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    // Declaring first container
    vector<int> v1 = { 1, 2, 3 };

    // Declaring second container without specifying
    // its size
    vector<int> v2;

    // Using std::back_inserter inside std::copy
    std::copy(v1.begin(), v1.end(), std::back_inserter(v2));
    // v2 now contains 1 2 3

    // Displaying v1 and v2
    cout << "v1 = ";

    int i;
    for (i = 0; i < 3; ++i) {
        cout << v1[i] << " ";
    }

    cout << "\nv2 = ";
    for (i = 0; i < 3; ++i) {
        cout << v2[i] << " ";
    }

    return 0;
}

Output:

v1 = 1 2 3
v2 = 1 2 3
```

## [std::`front_inserter`](https://www.geeksforgeeks.org/stdfront_inserter-in-cpp/)

`std::front_inserter` constructs a front-insert iterator that inserts new elements at the front of the
container to which it is applied. It is defined inside the header file .

+ With Dequeue

```text
#nclude <iostream>
#include <iterator>
#include <deque>
#include <algorithm>
using namespace std;
int main()
{
    // Declaring first container
    deque<int> v1 = { 1, 2, 3 };

    // Declaring second container for
    // copying values
    deque<int> v2 = { 4, 5, 6 };

    // Using std::front_inserter inside std::copy
    std::copy(v1.begin(), v1.end(), std::front_inserter(v2));
    // v2 now contains 3 2 1 4 5 6

    // Displaying v1 and v2
    cout << "v1 = ";

    int i;
    for (i = 0; i < 3; ++i) {
        cout << v1[i] << " ";
    }

    cout << "\nv2 = ";
    for (i = 0; i < 6; ++i) {
        cout << v2[i] << " ";
    }

    return 0;
}

Output:
v1 = 1 2 3
v2 = 3 2 1 4 5 6
```

+ `Reversing a container`

Now, since `std::front_inserter` inserts new elements at the beginning of the container, so we can perform the task of `reverse_copy()` just with the help of `copy()`,
such that we will create another container which contains the `reverse of present container`.

```text
// C++ program to demonstrate std::front_inserter
#include <iostream>
#include <iterator>
#include <deque>
#include <algorithm>
using namespace std;
int main()
{
    // Declaring first container
    deque<int> v1 = { 1, 2, 3 };

    // Declaring second container
    // for storing the reverse
    deque<int> v2;

    // Using std::front_inserter inside std::copy
    std::copy(v1.begin(), v1.end(), std::front_inserter(v2));
    // v2 now contains 3 2 1

    // Displaying v1 and v2
    cout << "v1 = ";

    int i;
    for (i = 0; i < 3; ++i) {
        cout << v1[i] << " ";
    }

    cout << "\nv2 = ";
    for (i = 0; i < 3; ++i) {
        cout << v2[i] << " ";
    }

    return 0;
}

Output:

v1 = 1 2 3
v2 = 3 2 1
```

## thread in C++
### sleep for function to delay

```text
#include <thread>
#include <chrono>

int main (void)
{
    // Delay between two successive line print
    const int sleepTime = 100;
    while(true) {
        this_thread::sleep_for(chrono::milliseconds(sleepTime));
    }
    return 0;
}
```
